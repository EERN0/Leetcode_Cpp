// 链表模拟栈
// Created by kang on 2023/8/16.

#include <iostream>

using namespace std;

// 链表节点
struct node {
    int val;
    node *next;

    explicit node(int x) : val(x), next(nullptr) {}
};

class Linklist {
public:
    // 添加元素
    void push(int x) {  // 头插法
        node *newNode = new node(x);
        newNode->next = head;
        head = newNode;
    }

    // 获取元素(获取头部元素)
    int top() {
        if (head) {
            int vaule = head->val;
            return vaule;
        }
        else {
            return -1;  // 链表头为空，报错
        }
    }

    // 删除元素，并返回该元素的值（删除头部元素）
    int pop() {
        if (head) {
            int value = head->val;
            node *temp = head;
            head = head->next;
            delete temp;
            return value;
        }
        else {
            return -1;
        }
    }

private:
    node *head;
};

int main() {
    Linklist mystack;
    mystack.push(3);
    mystack.push(2);
    mystack.push(1);
    int front = mystack.top();
    cout << front << endl;

    mystack.pop();

    front = mystack.top();
    cout << front << endl;

    return 0;
}