#include <iostream>
#include <vector>

using namespace std;
// https://leetcode-cn.com/problems/partition-list/

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) return NULL;
        ListNode *dummyHead = new ListNode(0, head); // 虚拟头节点
        ListNode *dummyHead_min = new ListNode(0); // 小链表的虚拟头节点
        ListNode *dummyHead_max = new ListNode(0); // 大连表的虚拟头节点

        ListNode *last = dummyHead;
        ListNode *last_min = dummyHead_min;
        ListNode *last_max = dummyHead_max;
        while (last->next != NULL) {
            if (last->next->val < x) {
                last_min->next = new ListNode(last->next->val);
                last_min = last_min->next;
            } else {
                last_max->next = new ListNode(last->next->val);
                last_max = last_max->next;
            }
            last = last->next;
        }
        // 拼接两个链表
        last_min->next = dummyHead_max->next;
        return dummyHead_min->next;
    }
};

class Solution2 {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) return NULL;

        ListNode *dummyHead_min = new ListNode(0); // 小链表的虚拟头节点
        ListNode *dummyHead_max = new ListNode(0); // 大连表的虚拟头节点

        ListNode *last_min = dummyHead_min;
        ListNode *last_max = dummyHead_max;
        while (head != NULL) {
            if (head->val < x) {
                last_min->next = head;
                last_min = last_min->next;
            } else {
                last_max->next = head;
                last_max = last_max->next;
            }
            head = head->next;
        }
        // 最后last_max后面要为NULL，例如 [1 4 2 3 5 1]时，如果 last_max 后面的结点不置为空，会指向结点1
        last_max->next = NULL;
        // 拼接两个链表
        last_min->next = dummyHead_max->next;
        return dummyHead_min->next;
    }
};
