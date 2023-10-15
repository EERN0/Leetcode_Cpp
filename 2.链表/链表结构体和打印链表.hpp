#ifndef LEETCODE_链表结构体和打印链表_HPP
#define LEETCODE_链表结构体和打印链表_HPP

#include <iostream>

using namespace std;

// 节点定义
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 打印输出链表
void printListNode(ListNode *head) {
    while (head != NULL) {
        if (head->next != NULL) {
            cout << head->val << "->";
        }
        else {
            cout << head->val << endl;
        }
        head = head->next;
    }
}

#endif //LEETCODE_链表结构体和打印链表_HPP
