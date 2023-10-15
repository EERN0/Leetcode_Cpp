/*
 * https://leetcode.cn/problems/merge-k-sorted-lists/
 * */
#include <vector>
#include <queue>
#include "链表结构体和打印链表.hpp"

using namespace std;

// 优先队列
class Solution {
public:
    // priority_queue默认是大根堆
    struct MyCompareVal {
        // 仿函数，让优先队列成为小根堆
        bool operator()(ListNode *l, ListNode *r) {
            return l->val > r->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return {};

        // 建一个小根堆
        priority_queue<ListNode *, vector<ListNode *>, MyCompareVal> minq;

        for (const auto &list: lists) {
            ListNode *cur = list;
            while (cur != nullptr) {
                minq.push(cur);
                cur = cur->next;
            }
        }

        auto *dummy = new ListNode(-1);
        ListNode *tail = dummy;

        while (!minq.empty()) {
            tail->next = minq.top();
            minq.pop();
            tail = tail->next;

            // 最后对尾巴的处理一定要注意
            if (minq.empty()) {
                tail->next = nullptr;
            }
        }
        return dummy->next;
    }
};

int main() {
    // 创建两个链表
    ListNode *list1 = new ListNode(-1);
    ListNode *last = list1;
    for (int i = 1; i <= 2; i++) {
        last->next = new ListNode(-1);
        last = last->next;
    }
    last->next = nullptr;   // 1->2->3->4->5->null

    ListNode *list2 = new ListNode(-2);
    ListNode *last2 = list2;
    for (int i = -2; i <= -1; i++) {
        last2->next = new ListNode(i);
        last2 = last2->next;
    }
    last2->next = nullptr;   // 2->4->6->8->null

    vector<ListNode *> lists = {list1, list2};
    Solution s;
    ListNode *res = s.mergeKLists(lists);

    printListNode(res);

    return 0;
}