// Created by caokang on 2023/5/9.
// 使用互斥锁和条件变量
#include <pthread.h>
#include <iostream>
#include <unistd.h>

using namespace std;

pthread_mutex_t m_mutex;
pthread_cond_t m_cond;
int cnt = 1;

void *fun(void *k) {        // flag = 0,1,2
    int flag = *(int *) (k);

    cout << "this is thread :" << flag + 1 << endl;

    while (cnt <= 100) {
        pthread_mutex_lock(&m_mutex);

        while ((cnt - 1) % 3 != flag) {
            pthread_cond_wait(&m_cond, &m_mutex);
        }

        cout << "thread " << flag + 1 << " :" << cnt++ << endl;

        if (cnt > 100) break;

        pthread_mutex_unlock(&m_mutex);
        pthread_cond_broadcast(&m_cond);
    }
}

int main() {
    pthread_mutex_init(&m_mutex, nullptr);
    pthread_cond_init(&m_cond, nullptr);

    pthread_t m_thread[3];
    int arg[3] = {0, 1, 2};     // 回调函数的参数

    for (int i = 0; i < 3; ++i) {
        pthread_create(&m_thread[i], nullptr, fun, &arg[i]);
    }

    sleep(5);   // 避免主线程先退出

    return 0;
}
