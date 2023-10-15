/*
 * https://leetcode.cn/problems/merge-two-sorted-lists/
 * */
#include "链表结构体和打印链表.hpp"
#include <iostream>

using namespace std;

// 迭代
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        auto cur1 = list1;
        auto cur2 = list2;
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val > cur2->val) {
                p->next = cur2;
                cur2 = cur2->next;
            }
            else {
                p->next = cur1;
                cur1 = cur1->next;
            }
            p = p->next;
        }
        // 退出while，cur1和cur2必有一个为null，即list1和list2最多只有一个没被合并完
//        p->next = (cur1 == nullptr) ? cur2 : cur1;
        if (cur1 == nullptr)    // list1走完了
            p->next = cur2;
        else p->next = cur1;

        return dummy->next;
    }
};


// 递归
class Solution_recursion {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};


/*
 * 变形题：抖音电商二面，要去除重复元素
 * */
class Solution_advance {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        ListNode *cur1 = list1;
        ListNode *cur2 = list2;

        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val < cur2->val) {
                p->next = cur1;
                cur1 = cur1->next;
            }
            else if (cur1->val == cur2->val) {
                p->next = cur1;
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            else {  // cur1->val > cur2->val
                p->next = cur2;
                cur2 = cur2->next;
            }
            p = p->next;
        }   // 退出while, 说明至少有一个链表走完了

        p->next = (cur1 == nullptr) ? cur2 : cur1;  // cur1走完，让p接上cur2

        return dummy->next;

    }
};

/*
 * 可以使用小根堆解决，lc23题
 * */

int main() {
    // 创建两个链表
    ListNode *list1 = new ListNode(1);
    ListNode *last = list1;
    for (int i = 2; i < 6; i++) {
        last->next = new ListNode(i);
        last = last->next;
    }
    last->next = nullptr;   // 1->2->3->4->5->null

    ListNode *list2 = new ListNode(1);
    ListNode *last2 = list2;
    for (int i = 2; i < 10; i++) {
        last2->next = new ListNode(i);
        last2 = last2->next;
        i++;
    }
    last2->next = nullptr;   // 2->4->6->8->null

    Solution s1;
    Solution_recursion s2;

    Solution_advance s3;    // 去除重复元素
    ListNode *L = s3.mergeTwoLists(list1, list2);
    printListNode(L);
}