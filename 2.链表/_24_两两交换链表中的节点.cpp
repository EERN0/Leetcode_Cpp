/*
 * K个一组翻转链表，当K=2的情况
 * https://leetcode.cn/problems/swap-nodes-in-pairs/
 * */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 递归(和203题的递归思路一样)
class Solution_recursion {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        // 因为是两两交换，递归处理第2个节点之后的节点， [1->2]->[3->4]->5->null
        head->next->next = swapPairs(head->next->next);

        // 头节点和下一个节点交换
        ListNode *temp = head->next;
        head->next = head->next->next;
        temp->next = head;

        return temp;
    }
};

// 非递归
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *dummyhead = new ListNode(-1, head);
        ListNode *cur = dummyhead;      // cur负责交换它后面两个节点, cur->[1->2]->3 ——> cur->[2->1]->3

        // dummy->1->2->3->4->5->null
        while (cur->next != nullptr && cur->next->next != nullptr) {    // 处理奇数、偶数个节点
            ListNode *temp = cur->next;
            ListNode *temp2 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = temp;
            temp->next = temp2;         // cur->2->1->3->4->5->null

            cur = cur->next->next;      // 2->1->3(cur)->4->5->null
        }
        return dummyhead->next;
    }
};