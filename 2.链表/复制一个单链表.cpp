#include <iostream>
#include <vector>
#include<string>

using namespace std;
// https://leetcode-cn.com/problems/partition-list/

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 反转链表 —— 迭代
// 反转链表得到的是原链表反转后的，原链表改动了！
ListNode *reverseList(ListNode *head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode *pre = NULL;   // 逆置后，当前结点的next结点
    ListNode *cur = head;   // 当前结点
    while (cur != NULL) {
        ListNode *temp = cur->next;   // 临时结点，暂存cur结点的下一个结点，用于cur后移
        cur->next = pre;              // cur（当前结点）指向逆置后它前面的结点
        pre = cur;                    // 前指针后移
        cur = temp;                   // 当前指针后移
    }
    return pre;
}

// 打印输出链表
void printListNode(ListNode *head) {
    while (head != NULL) {
        if (head->next != NULL) {
            cout << head->val << "->";
        } else {
            cout << head->val << endl;
        }
        head = head->next;
    }
}


void test() {
    ListNode *head = new ListNode(0);
    ListNode *last = head;
    // 给链表赋值
    for (int i = 1; i < 3; i++) {
        last->next = new ListNode(i);
        last = last->next;
    }
    for (int i = 2; i >= 0; i--) {
        last->next = new ListNode(i);
        last = last->next;
    }
    last->next = NULL;
    printListNode(head);    // 0->1->2->2->1->0->NULL
    last = head;

    // 复制一份head，成为一个新链表 dummyhead2
    ListNode *dummyhead2 = new ListNode(0);
    ListNode *last2 = dummyhead2;
    while (last != NULL) {
        last2->next = new ListNode(last->val);
        last = last->next;
        last2 = last2->next;
    }
    last2->next = NULL;
    // 新链表原地逆置
    ListNode *reverseHead = reverseList(dummyhead2->next);

    // 判断是否为回文链表
    int flag = 1;
    while (head != NULL) {
        if (head->val != reverseHead->val) {
            flag = 0;
        }
        head = head->next;
        reverseHead = reverseHead->next;
    }
    if (flag == 1) {
        cout << "head是回文链表" << endl;
    } else{
        cout << "head不是回文链表" << endl;
    }
    printListNode(reverseHead);
}

int main() {
    test();
    return 0;
}
