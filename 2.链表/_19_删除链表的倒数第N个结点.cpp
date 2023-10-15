/*
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
 * */
#include <iostream>
#include "链表结构体和打印链表.hpp"
#include <stack>

using namespace std;

// 拿到链表的长度，遍历了两次
// 时间复杂度O(L), 空间复杂度O(1)
class Solution_traversalTwice {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr || (head->next == nullptr && n == 1)) return nullptr;

        int length = 0;
        ListNode *p = head;
        while (p) {
            length++;
            p = p->next;
        }

        if (n == length) return head->next;   // 要删除头节点，直接返回头节点的后一个节点

        ListNode *dummy = new ListNode(-1, head);
        ListNode *q = dummy;

        int count = 0;
        while (q->next) {       // 删除节点A，要走到A的前一个节点，让 A->next=A->next->next
            q = q->next;
            count++;
            if (count == length - n) {
                ListNode *temp = q->next;
                q->next = q->next->next;
                delete temp;
                break;
            }
        }
        return dummy->next;
    }
};


/*
 * 遍历一次 —— 快慢指针
 * 快指针先走n步，然后快、慢指针一下走一步，当快指针走到null，慢指针指向的是倒数第n个节点
 * 要找到low指针的前一个节点，才好删除low指向的节点
 * 所以，fast要先走n+1步，再fast和low一起走，这样low指向的是倒数n个节点的前一个节点
 *
 * 时间O(L), 空间O(1)
 * */
class Solution_traversalOnce {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr || (head->next == nullptr && n == 1)) return nullptr;
        auto dummy = new ListNode(-1, head);
        ListNode *fast = dummy, *low = dummy;

        n = n + 1;      // fast先走n+1步
        while (n-- && fast != nullptr) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            low = low->next;
        }

        // 删除节点
        auto temp = low->next;
        low->next = low->next->next;
        delete temp;

        return dummy->next;
    }
};


/*
 * 使用栈，遍历一次
 * 【把节点压栈，它的next域没有改变】
 * 时间O(L), 空间O(L)
 * */
class Solution_stack {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr) return nullptr;

        stack<ListNode *> stack;
        auto dummy = new ListNode(-1, head);
        auto cur = dummy;

        // 压栈
        while (cur) {
            stack.push(cur);
            cur = cur->next;
        }

        // 弹出后面n个节点，要拿到倒数第(n+1)个节点
        for (int i = 0; i < n; i++) {
            stack.pop();
        }
        ListNode *prev = stack.top();
        ListNode *temp = prev->next;
        prev->next = prev->next->next;
        delete temp;

        return dummy->next;
    }
};


int main() {
    Solution_traversalTwice s1;
    Solution_traversalOnce s2;
    Solution_stack s3;

    ListNode *head = new ListNode(1);
    ListNode *last = head;
    for (int i = 2; i < 6; i++) {
        last->next = new ListNode(i);
        last = last->next;
    }
    last->next = nullptr;   // 1->2->3->4->5->null

    ListNode *L = s3.removeNthFromEnd(head, 3);
    printListNode(L);
}