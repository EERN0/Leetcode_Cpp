// Created by caokang on 2023/4/28.
// https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
#include "../2.链表/链表结构体和打印链表.hpp"

using namespace std;

// 双指针，快慢指针
// 快指针先走k步(快、慢指针的间距是k)，然后快、慢指针同时一下走一步，当快指针走到null，慢指针走到的就是倒数第k个节点
class Solution1 {
public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        ListNode *fast = head;
        ListNode *slow = head;
        int copy_k = k;
        while (copy_k--) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};


// 遍历两次链表：先拿到链表的长度length，再去遍历一次链表，倒数第k个节点是第(length-k+1)个节点
class Solution2 {
public:
    ListNode *getKthFromEnd(ListNode *head, int k) {
        int length = 0;
        auto cur = head;
        while (cur != nullptr) {
            length++;
            cur = cur->next;
        }

        int index = length - k + 1; // 倒数第k个节点是第index个节点
        cur = head;
        while (index--) {
            if (index == 0) {
                return cur;
            }
            cur = head->next;
        }

        return nullptr;
    }
};