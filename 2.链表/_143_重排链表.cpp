/*
 * https://leetcode.cn/problems/reorder-list/
 * */
#include "链表结构体和打印链表.hpp"
#include <iostream>

using namespace std;

class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return;

        // 找到中间节点
        ListNode *midNode = findMid(head);

        // 中间节点右侧的节点
        ListNode *L_right = midNode->next;

        // 中间节点及左侧的节点为head
        midNode->next = nullptr;

        // 反转中间节点右侧节点
        L_right = reverseList(L_right);

        // 合并中间节点之前的链表、中间节点及之后的链表(已经反转过的)
        mergeList(head, L_right);
    }

    // 查找中间节点
    ListNode *findMid(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *fast = head;
        ListNode *low = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            low = low->next;
        }
        return low;
    }

    // 反转链表
    ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *cur = head;
        ListNode *prev = nullptr;
        // 1->2->3->4->null
        while (cur != nullptr) {
            ListNode *temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }

    // 合并两个链表
    ListNode *mergeList(ListNode *L1, ListNode *L2) {
        if (L1 == nullptr) return L2;
        if (L2 == nullptr) return L1;

        auto dummy = new ListNode(-1, L1);
        while (L1 != nullptr && L2 != nullptr) {
            // 每次保留L1和L2的下一个节点
            ListNode *L1_next = L1->next;
            ListNode *L2_next = L2->next;

            L1->next = L2;
            L1 = L1_next;
            if (L1 == nullptr) {     // 不加上判断，就要保证 L1 长于 L2
                return L1;
            }

            L2->next = L1;
            L2 = L2_next;
        }
        return dummy->next;
    }
};

int main() {
    // 创建两个链表
    ListNode *list = new ListNode(1);
    ListNode *last = list;
    for (int i = 2; i < 6; i++) {
        last->next = new ListNode(i);
        last = last->next;
    }
    last->next = nullptr;   // 1->2->3->4->5->null


    Solution s1;
    s1.reorderList(list);
    printListNode(list);
}