/*
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/
 * */
#include "链表结构体和打印链表.hpp"

using namespace std;

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *dummy = new ListNode(-1, head);
        ListNode *cur = head;
        ListNode *pre = dummy;    // 删除节点，必须保留前一个节点

        while (cur != nullptr && cur->next != nullptr) {
            if (cur->val == cur->next->val) {   // 和下一个节点的值一样，删除值重复的节点
                int val = cur->val;
                while (cur != nullptr && cur->val == val) {    // 走到要删除节点的后一个节点
                    cur = cur->next;
                }
                // 删除值重复节点
                pre->next = cur;
            }
            else {  // 和下一个节点的值不一样
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};