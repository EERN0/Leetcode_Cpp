/*
 * hard
 * https://leetcode.cn/problems/reverse-nodes-in-k-group/
 * */
#include <iostream>
#include <stack>
#include "链表结构体和打印链表.hpp"
using namespace std;


/*
 * 方法一：用栈实现K个一组翻转，用栈只用一趟扫描，空间复杂度是O(k)
 * 栈只存放节点，入栈后，原链表并没有被破坏
 * */
class Solution_stack {
public:
    // dummy->1->2->3->4->5->null
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr) return head;

        stack<ListNode *> stack;
        int count = 0;  // 统计入栈节点数
        ListNode *cur = head;
        ListNode *dummyhead = new ListNode(-1, head);
        ListNode *p = dummyhead;    // 让p参与循环

        while (true) {
            count = 0;
            // 压栈
            while (cur != nullptr && count < k) {
                stack.push(cur);
                cur = cur->next;
                count++;
            }

            // 若栈中节点数小于k, 表示后面节点不用交换, 即不用弹栈
            if (count < k) {
                break;
            }

            while (!stack.empty()) {    // dummy->3->2->1-
                p->next = stack.top();  // 栈顶元素
                stack.pop();            // 弹出栈顶
                p = p->next;
            }
            p->next = cur;      // dummy->3->2->1(p)->4(cur)->5->null
        }
        return dummyhead->next;
    }
};

int main() {
    Solution_stack s1;

    ListNode *head = new ListNode(1);
    ListNode *last = head;
    for (int i = 2; i < 6; i++) {
        last->next = new ListNode(i);
        last = last->next;
    }
    last->next = nullptr;   // 1->2->3->4->5->null
    ListNode *L = s1.reverseKGroup(head, 2);
    printListNode(L);
}