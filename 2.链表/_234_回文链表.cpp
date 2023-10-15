// https://leetcode-cn.com/problems/partition-list/
#include <iostream>
#include <vector>
#include<string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution234 {
public:
    // 找到中间节点（偶数节点为中左）
    ListNode *findMidNode(ListNode *head) {
        ListNode *dummy = new ListNode(-1, head);
        ListNode *slow = dummy;
        ListNode *fast = dummy;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    // 反转链表
    ListNode *reverse(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *cur = head;
        ListNode *prev = nullptr;
        while (cur) {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }

    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;

        ListNode *cur1 = head;
        ListNode *midLeft = findMidNode(head);
        ListNode *cur2 = midLeft->next;
        midLeft->next = nullptr;

        // 反转右边的链表
        cur2 = reverse(cur2);

        while (cur1 && cur2) {
            if (cur1->val == cur2->val) {
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            else {
                return false;
            }
        }

        // 奇数节点情况下，左边链表节点数肯定多余右边链表的
        // 退出while时，左边链表还有一个节点没走完
        return true;
    }
};