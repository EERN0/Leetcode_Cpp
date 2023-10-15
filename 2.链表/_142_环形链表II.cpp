/*
 * https://leetcode.cn/problems/linked-list-cycle-ii/
 * */
#include "链表结构体和打印链表.hpp"
#include <unordered_set>

using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        unordered_set<ListNode *> set;
        auto cur = head;

        while (cur) {
            set.insert(cur);
            cur = cur->next;

            /*
             * unordered_set_name.find(key)
             * 返回值：- 若key在集合中，返回元素key的迭代器，
             *        - 若key不在集合中，返回指向unordered_set末尾的迭代器(unordered_set_name.end())
             * */
//            if (set.find(cur) != set.end()) {
//                return cur;
//            }

            if (set.count(cur)) {   // cur = cur->next; 若cur在集合中还出现过，说明有环
                return cur;
            }
        }
        return nullptr;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    ListNode *last = head;
    for (int i = 2; i < 3; i++) {
        last->next = new ListNode(i);
        last = last->next;
    }
    last->next = head;   // 1->2->1;

    Solution s1;
    ListNode *L = s1.detectCycle(head);
//    printListNode(L);
}