/*
 * https://leetcode.cn/problems/linked-list-cycle/
 * */
#include "链表结构体和打印链表.hpp"
#include <unordered_set>

using namespace std;

// 哈希表，存节点
class Solution1 {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        ListNode *cur = head;

        unordered_set<ListNode *> set;
        while (cur != nullptr) {
            set.insert(cur);
            cur = cur->next;

            // 判断节点cur是否在哈希表中出现过
            if (set.count(cur)) {
                return true;
            }
        }
        return false;
    }
};

// 快慢指针
class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        auto slow = head, fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};