/*
 * 好难啊！！
 * https://leetcode.cn/problems/sort-list/
 * */
#include "链表结构体和打印链表.hpp"

// 时间O(nlogn)，空间O(n)，答案还有快排、空间O(1)的方法
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return mergeSort(head);
    }

    // 归并排序
    ListNode *mergeSort(ListNode *head) {
        // 递归结束条件，只有1个节点或0个节点时返回
        if (head == nullptr || head->next == nullptr) return head;

        auto slow = head;
        auto fast = head;
        // pre是中间节点mid的前一个节点
        ListNode *pre = nullptr;    // 必须记录mid前一个节点，不然死循环了

        while (fast != nullptr && fast->next != nullptr) {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        // 中间节点(偶数个节点时，是中左节点)
        auto mid = slow;

        // 对右半部分（mid及之后的节点）归并排序
        auto right = mergeSort(mid);    // 非mid->next

        // 左半部分（mid之前的），尾部和右半部分断开，再归并排序
        pre->next = nullptr;
        auto left = mergeSort(head);

        // 退出mergeSort()递归, 要么是1个节点，要么是null, 按顺序合并两个节点，或者只合并1个节点
        return mergeTwoList2(left, right);
    }


    // lc21题-合并两个有序链表（递归）
    ListNode *mergeTwoList1(ListNode *L1, ListNode *L2) {
        // 递归结束条件
        if (L1 == nullptr) return L2;
        if (L2 == nullptr) return L1;

        if (L1->val <= L2->val) {
            L1->next = mergeTwoList1(L1->next, L2);
            return L1;
        }
        else {
            L2->next = mergeTwoList1(L1, L2->next);
            return L2;
        }
    }

    // lc21题-合并两个有序链表（迭代）
    ListNode *mergeTwoList2(ListNode *L1, ListNode *L2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;  // cur是构建链表的扫描指针

        while (L1 != nullptr && L2 != nullptr) {
            if (L1->val <= L2->val) {
                cur->next = L1;
                L1 = L1->next;
            }
            else {
                cur->next = L2;
                L2 = L2->next;
            }
            cur = cur->next;
        }

        // 出while循环，L1走完了，或L2走完了
        cur->next = (L1 == nullptr) ? L2 : L1;  // L1走完了，cur连上L2，否则连L1

        return dummy->next;
    }
};


int main() {
    ListNode *head = new ListNode(4, nullptr);
    ListNode *node1 = new ListNode(2, nullptr);
    ListNode *node2 = new ListNode(1, nullptr);
    ListNode *node3 = new ListNode(3, nullptr);

    head->next = node1, node1->next = node2, node2->next = node3, node3->next = nullptr;

    Solution s1;
    auto res = s1.sortList(head);

    while (res != nullptr) {
        if (res->next != nullptr) {
            cout << res->val << "->";
        }
        else {
            cout << res->val;
        }
        res = res->next;
    }
    cout << endl;


    return 0;
}