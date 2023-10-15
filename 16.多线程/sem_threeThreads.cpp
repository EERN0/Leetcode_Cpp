// 信号量机制，三线程交替打印0~100

// 线程1先运行，让线程1唤醒线程2，线程2唤醒线程3，线程3唤醒线程1
// Created by caokang on 2023/5/9.

#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem1, sem2, sem3;
int num = 1;    // 要打印的数字

void *thread1(void *arg) {
    while (true) {
        sem_wait(&sem1);    // 消耗一个sem1, 没有就阻塞等待

        if (num > 100) {
            break;  // 结束整个进程
        }

        printf("thread 1 : %d\n", num++);

        sem_post(&sem2);    // 生产一个sem2，唤醒阻塞的线程2
    }
    return nullptr;
}

void *thread2(void *arg) {
    while (true) {
        sem_wait(&sem2);    // 消耗一个sem2, 没有就阻塞等待

        if (num > 100) {
            break;  // 结束整个进程
        }

        printf("thread 2 : %d\n", num++);

        sem_post(&sem3);    // 生产一个sem3，唤醒阻塞的线程3
    }
    return nullptr;
}

void *thread3(void *arg) {
    while (true) {
        sem_wait(&sem3);    // 消耗一个sem3, 没有就阻塞等待

        if (num > 100) {
            break;  // 结束整个进程
        }

        printf("thread 3 : %d\n", num++);

        sem_post(&sem1);    // 生产一个sem1，唤醒阻塞的线程1
    }
    return nullptr;
}


int main() {
    // 初始化信号量
    sem_init(&sem1, 0, 1);  // 一开始要启动线程1，不然死锁了
    sem_init(&sem2, 0, 0);
    sem_init(&sem3, 0, 0);

    pthread_t thread[3];

    pthread_create(&thread[0], nullptr, thread1, nullptr);
    pthread_create(&thread[1], nullptr, thread2, nullptr);
    pthread_create(&thread[2], nullptr, thread3, nullptr);

    // 设置线程分离
    for (int i = 0; i < 3; ++i) {
        pthread_detach(thread[i]);
    }

    // 销毁信号量
    sem_destroy(&sem1);
    sem_destroy(&sem2);
    sem_destroy(&sem3);

    sleep(2);   // 避免主进程直接结束

    return 0;
}
