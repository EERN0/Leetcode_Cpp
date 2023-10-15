/*
 * https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
 * */
#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

/*
 * 不是节点的值相同，而是指针（节点地址）相同
 * */

// 哈希表
// 把链表headA的所有节点存到哈希表中，遍历链表headB，若在哈希表中出现过，说明是两链表开始相交的部分
class Solution1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        unordered_set < ListNode * > myset;
        auto curA = headA;
        while (curA) {
            // 把curA加入到哈希表中
            myset.insert(curA);
            curA = curA->next;
        }

        auto curB = headB;
        while (curB) {
            // curB节点在哈希表中出现了，说明是headA和headB的相交部分
            if (myset.count(curB)) {
                return curB;
            }
            curB = curB->next;
        }

        return nullptr;
    }
};

// 双指针
class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0, lenB = 0;

        // headA,headB的长度
        while (curA != nullptr) {
            lenA++;
            curA = curA->next;
        }
        while (curB != nullptr) {
            lenB++;
            curB = curB->next;
        }

        // 让headA长于headB
        if (lenA < lenB) {
            swap(lenA, lenB);
            swap(headA, headB);
        }

        curA = headA;
        curB = headB;

        int n = lenA - lenB;
        while (n--) {
            curA = curA->next;
        }

        while (curA != nullptr) {
            if (curA == curB) return curA;
            else {
                curA = curA->next;
                curB = curB->next;
            }
        }

        return nullptr;
    }
};


class Solution2_1 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode *curA = headA;
        ListNode *curB = headB;

        while (curA != curB) {    // curA != curB说明还没找到相交节点
            curA = (curA == nullptr) ? headB : curA->next;
            curB = (curB == nullptr) ? headA : curB->next;
        }
        return curA;
    }
};
