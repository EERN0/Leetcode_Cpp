/*
 * https://leetcode-cn.com/problems/remove-linked-list-elements/
 * */
#include <iostream>
#include <vector>

using namespace std;
/*
 *         if (head == NULL) return NULL;

        // 链表头节点可能要被删除，因此创建虚拟头节点 newHead, newHead->next = head
        ListNode *newHead = new ListNode(0, head);   // 初始化一个虚拟头节点，值设为0，next为head

        ListNode *temp = newHead;
        while (temp->next != NULL) {
            if (temp->next->val == val) {
                temp->next = temp->next->next;
            }
            else {
                temp = temp->next;
            }
        }
        return newHead->next;
 * */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * 要删除一个节点，必须找到它前面的节点
 * */

// 使用虚拟头节点
class Solution_dummyhead {
public:
    ListNode *removeElements(ListNode *head, int val) {
        // 要删除一个节点，必须找到它前面一个节点a，a->next = a->next->next表示删除了这个节点
        if (head == nullptr) return nullptr;
        ListNode *dummyhead = new ListNode(0, head);    // dummyhead->next = head;

        ListNode *cur = dummyhead;
        while (cur->next) {
            if (cur->next->val == val) {
                ListNode *temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else cur = cur->next;
        }

        return dummyhead->next;
    }
};

// 不使用虚拟头节点
class Solution_nodummyhead {
public:
    ListNode *removeElements(ListNode *head, int val) {
//        if (head == nullptr) return nullptr;

        // 要删除的数正好是头节点head的val
        while (head != nullptr && head->val == val) {
            head = head->next;
        }

        ListNode *cur = head;
        while (cur != nullptr && cur->next != nullptr) {
            if (cur->next->val == val) cur->next = cur->next->next;
            else cur = cur->next;
        }

        return head;
    }
};


// 递归
class Solution_recursion {
public:
    ListNode *removeElements(ListNode *head, int val) {
        if (head == nullptr) return nullptr;

        // head后面的节点，就是删除了包含val的节点
        head->next = removeElements(head->next, val);

        return head->val == val ? head->next : head;
    }
};
