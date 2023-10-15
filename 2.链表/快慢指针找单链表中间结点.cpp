#include <iostream>
#include <vector>
#include<string>

using namespace std;

// 快慢指针找【中左】结点，要加上虚拟头结点

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 打印输出链表
void printListNode(ListNode *head) {
    while (head != nullptr) {
        if (head->next != nullptr) {
            cout << head->val << "->";
        } else {
            cout << head->val << endl;
        }
        head = head->next;
    }
}

// 快慢指针，返回链表的中间结点（结点个数为偶数时，返回中间偏左的结点）
// 返回中间结点的指针：快指针走两步，满指针走一步，当快指针走到头且慢指针走了一步后，返回慢指针
ListNode *midList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode *low = new ListNode(0,head);
    ListNode *high = low;

    while (high != nullptr && high->next != nullptr) {  // 必须满足两个条件
        high = high->next->next;
        low = low->next;
    }
    return low;
}

void test() {
    ListNode *head = new ListNode(0);
    ListNode *last = head;
    for (int i = 1; i < 7; i++) {
        last->next = new ListNode(i);
        last = last->next;
    }
    for (int i = 2; i >= 0; i--) {
        last->next = new ListNode(i);
        last = last->next;
    }
    last->next = nullptr;
    printListNode(head);    // 0->1->2->3->4->2->1->0

    ListNode *midNode = midList(head);
    cout << "中间结点的值为：" << midNode->val << endl;
}

int main() {

    test();
    return 0;
}



