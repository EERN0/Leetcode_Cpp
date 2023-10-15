// https://leetcode.cn/problems/remove-duplicates-from-sorted-list/
// Created by caokang on 2023/10/3.
#include "链表结构体和打印链表.hpp"

class Solution83 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;

        ListNode *dummy = new ListNode(-1, head);
        ListNode *p = dummy;

        ListNode *cur = head;
        while (cur && cur->next) {
            // 遇到重复的元素，接着往后面走
            while (cur && cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            }
            // 出while，说明cur和下一个节点值不同
            p->next = cur;
            p = p->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};