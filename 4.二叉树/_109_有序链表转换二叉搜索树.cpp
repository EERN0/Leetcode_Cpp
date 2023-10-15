// Created by caokang on 2023/8/29.
// https://leetcode.cn/problems/convert-sorted-list-to-binary-search-tree/

#include "二叉树结构体.hpp"
#include "../2.链表/链表结构体和打印链表.hpp"

class Solution109 {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == nullptr) return nullptr;

        // 链表只有一个节点
        if (head->next == nullptr) {
            return new TreeNode(head->val);
        }

        // 找中右节点slow
        ListNode *slow = head, *fast = head;
        ListNode *prev = nullptr;           // 中右节点的前一个节点
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        // slow是中右节点，作为根
        TreeNode *root = new TreeNode(slow->val);

        prev->next = nullptr;   // 左子树链表，尾巴置为null
        ListNode *left = head;
        ListNode *right = slow->next; // 右子树链表

        root->left = sortedListToBST(left);
        root->right = sortedListToBST(right);
        return root;
    }
};