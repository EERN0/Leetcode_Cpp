#include <iostream>
#include <vector>
#include "链表结构体和打印链表.hpp"
using namespace std;

// https://leetcode-cn.com/problems/add-two-numbers/

class Solution1 {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode *dummyHead = new ListNode(0);   // dummyHead作为虚拟头节点，用于返回新的链表，不能动
        ListNode *last = dummyHead;                 // last作为新链表的最后节点
        // 进位值
        int carry = 0;

        while (l1 != NULL || l2 != NULL) {
            int l1_val = (l1 != NULL) ? l1->val : 0;    // l1若非空，取出l1节点的值，若为空，则置为0
            int l2_val = (l2 != NULL) ? l2->val : 0;    // l2若非空，取出l2节点的值，若为空，则置为0
            int sum = l1_val + l2_val + carry;          // 节点相加值
            // 进位
            carry = sum / 10;

            // 创建一个节点记录sum的个位，接到链表后面
            last->next = new ListNode(sum % 10);
            last = last->next;

            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }
        // while循环退出后，还要检查最后的进位
        // 当 l1、l2均为NULL退出循环时，会留下进位carry，必须将进位接到新链表的后面
        if (carry == 1) {
            last->next = new ListNode(carry);
        }
        return dummyHead->next;
    }
};

class Solution2 {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        ListNode *dummyHead = new ListNode(0);   // dummyHead作为虚拟头节点，用于返回新的链表，不能动
        ListNode *last = dummyHead;                 // last作为新链表的最后节点
        // 进位值
        int carry = 0;

        // while循环退出后，还要检查最后的进位
        // 当 l1、l2均为NULL退出循环时，会留下进位carry，必须将进位接到新链表的后面
        // 最后一次相加，若有进位，carry为1，进入循环，sum = carry，创建新节点加入到新链表中
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int l1_val = (l1 != NULL) ? l1->val : 0;    // l1若非空，取出l1节点的值，若为空，则置为0
            int l2_val = (l2 != NULL) ? l2->val : 0;    // l1若非空，取出l1节点的值，若为空，则置为0
            int sum = l1_val + l2_val + carry;          // 节点相加值
            // 进位
            carry = sum / 10;

            // 创建一个节点记录sum的个位，接到链表后面
            last->next = new ListNode(sum % 10);
            last = last->next;

            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }
        return dummyHead->next;
    }
};