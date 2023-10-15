/*
 * https://leetcode.cn/problems/reverse-linked-list-ii/
 * */
#include <vector>
#include "链表结构体和打印链表.hpp"

using namespace std;

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (!head || !head->next || left==right) return head;
        ListNode *dummy = new ListNode(-1, head);

        ListNode *start = nullptr;
        ListNode *end = nullptr;

        ListNode *left1 = nullptr;

        ListNode *cur = dummy;  // 为了处理 3->5  1 2的情况
        ListNode *pre = nullptr;
        int curIndex = 0;

        while (cur != nullptr) {
            if (curIndex == left - 1) start = cur;  // 保留left的前一个节点

            if (curIndex <= right) {
                cur = cur->next;
                curIndex++;
            }
            else {
                break;
            }

            // 在[left, right]区间内反转链表，[left, right]反转部分链表的头节点是pre
            while (left <= curIndex && curIndex <= right) {
                if (curIndex == left) left1 = cur;

                ListNode *temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
                curIndex++;

                if (curIndex == right + 1) end = cur;   // 保留right的后一个节点
            }
        }

        // 连上链表
        left1->next = end;
        start->next = pre;

        return dummy->next;
    }
};

int main() {
    auto *head = new ListNode(1);
    ListNode *last = head;
    for (int i = 2; i <= 2; i++) {
        last->next = new ListNode(i);
        last = last->next;
    }
    last->next = nullptr;

    Solution s;
    ListNode *res = s.reverseBetween(head, 1, 2);

    printListNode(res);

    return 0;
}