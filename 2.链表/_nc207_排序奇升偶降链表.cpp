// https://www.nowcoder.com/practice/3a188e9c06ce4844b031713b82784a2a?tpId=117
// Created by kang on 2023/8/25.
// 一个奇位升序，偶位降序的链表，重新给它排序

#include "链表结构体和打印链表.hpp"

class Solution {
public:
    ListNode *sortLinkedList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        // 链表分为奇数链表+偶数链表
        ListNode *list1 = new ListNode(-1);
        ListNode *list2 = new ListNode(-1);
        ListNode *p1 = list1, *p2 = list2;

        int cnt = 1;
        ListNode *cur = head;

        while (cur) {
            if (cnt % 2 == 1) { // 奇数节点
                p1->next = cur;
                p1 = p1->next;
            }
            else {
                p2->next = cur;
                p2 = p2->next;
            }
            cur = cur->next;
            cnt++;
        }
        // 收尾
        p1->next = nullptr, p2->next = nullptr;
        // list1是升序的，list2是降序的，要逆置list2链表
        list2->next = reverse(list2->next);

        return mergeTwoLists(list1->next, list2->next);
    }

    // 合并两个升序链表
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        ListNode *dummy = new ListNode(-1, nullptr);
        ListNode *p = dummy;
        ListNode *i1 = l1, *i2 = l2;
        while (i1 != nullptr && i2 != nullptr) {
            if (i1->val <= i2->val) {
                p->next = i1;
                p = p->next;
                i1 = i1->next;
            }
            else {
                p->next = i2;
                p = p->next;
                i2 = i2->next;
            }
        }
        if (i1 == nullptr) {
            p->next = i2;
        }
        else {
            p->next = i1;
        }
        return dummy->next;
    }

    // 反转链表
    ListNode *reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *p = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};

int main() {
    ListNode *node6 = new ListNode(1);
    ListNode *node5 = new ListNode(3, node6);
    ListNode *node4 = new ListNode(2, node5);
    ListNode *node3 = new ListNode(2, node4);
    ListNode *node2 = new ListNode(3, node3);
    ListNode *node1 = new ListNode(1, node2);

    Solution solution;
    ListNode *res = solution.sortLinkedList(node1);

    while (res != nullptr) {
        if (res->next != nullptr) {
            cout << res->val << "->";
        }
        else {
            cout << res->val;
        }
        res = res->next;
    }
    cout << endl;
}