#include "../2.链表/链表结构体和打印链表.hpp"

using namespace std;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        int carry = 0;  // 进位

        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;

        while (l1 != nullptr || l2 != nullptr) {
            int l1_val = (l1 != nullptr) ? l1->val : 0;
            int l2_val = (l2 != nullptr) ? l2->val : 0;

            int sum = l1_val + l2_val + carry;

            carry = sum / 10;   // 进位

            cur->next = new ListNode(sum % 10);
            cur = cur->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // 退出while，l1和l2都为null，考虑进位carry
        if (carry == 1) {
            cur->next = new ListNode(carry, nullptr);
        }

        return dummy->next;
    }
};