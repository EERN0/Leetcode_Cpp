// https://leetcode-cn.com/problems/reverse-linked-list/
#include <iostream>
#include <vector>
#include "链表结构体和打印链表.hpp"

using namespace std;


// 反转链表 —— 迭代(双指针)
class Solution1 {
public:
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *pre = nullptr;   // 逆置后，当前结点的next结点
        ListNode *cur = head;      // 当前结点
        while (cur != nullptr) {
            ListNode *temp = cur->next;   // 临时结点，暂存cur结点的下一个结点，用于cur后移
            cur->next = pre;              // cur（当前结点）指向逆置后它前面的结点
            pre = cur;                    // 前指针后移
            cur = temp;                   // 当前指针后移
        }
        return pre;
    }
};

// 反转链表 —— 递归1, 参照上面的双指针法
class Solution2 {
public:
    ListNode *reverse(ListNode *cur, ListNode *pre) {
        if (cur == nullptr) return pre;

        ListNode *temp = cur->next;
        cur->next = pre;
        return reverse(temp, cur);
    }

    ListNode *reverseList(ListNode *head) {
        return reverse(head, nullptr);
    }
};

// 反转链表 —— 递归2
class Solution3 {
public:
    ListNode *reverseList(ListNode *head) {
        // 递归结束出口
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *p = reverseList(head->next);  // 递归调用，将一个大问题拆成子问题
        head->next->next = head;
        head->next = nullptr;

        return p;   // 返回链表反转后的头结点
    }
};


int main() {
    auto *head = new ListNode(0);
    ListNode *last = head;
    for (int i = 1; i < 5; i++) {
        last->next = new ListNode(i);
        last = last->next;
    }
    last->next = nullptr;


    Solution1 s1;
    Solution2 s2;
    printListNode(s1.reverseList(head));
    return 0;
}