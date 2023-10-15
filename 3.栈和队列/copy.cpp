//
// Created by caokang on 2023/5/7.
//

// 方法一：正常栈 + 最小栈
class MinStack1 {
public:
    // 正常栈，用来存放正常数据
    stack<int> stack1;
    // 最小栈，用来存放最小数据，元素个数与正常栈一一对应 —— 为了使getMin()方法时间复杂度O(1)
    stack<int> minStack;

    // 初始化
    MinStack1() {

    }

    void push(int val) {
        stack1.push(val);
        if (minStack.empty()) {
            minStack.push(val);
        } else {
            // 将正常栈入栈的元素与最小栈的栈顶元素比较，将最小数据的入栈
            minStack.push(min(minStack.top(), val));
        }
    }

    void pop() {
        stack1.pop();
        minStack.pop();
    }

    int top() {
        return stack1.top();
    }

    int getMin() {
        return minStack.top();
    }
};

// 方法二：利用链表
struct LinkNode {
    int val;
    int minNum;
    LinkNode *next;

    LinkNode() : val(0), next(nullptr) {}

    LinkNode(int x) : val(x), next(nullptr) {}

    LinkNode(int x, int y) : val(x), minNum(y), next(nullptr) {}

    LinkNode(int x, int y, LinkNode *next) : val(x), minNum(y), next(next) {}
};

class MinStack {
public:
    // 虚拟头结点
    LinkNode *head = new LinkNode(0, 0, NULL);

    MinStack() {    // 默认构造

    }

    // 头插法
    void push(int val) {
        if (head->next == NULL) {   // 链表为空，插入时最小值为val
            head->next = new LinkNode(val, val);
            head->next->next = NULL;
        } else {    // 链表非空
            LinkNode *temp = head->next;
            head->next = new LinkNode(val, min(temp->minNum, val));
            head->next->next = temp;
        }
    }

    void pop() {
        if (head->next != NULL) {   // 链表非空
            LinkNode *p = head->next;
            head->next = head->next->next;
            delete p;
        }
    }

    int top() {
        return head->next->val;
    }

    int getMin() {
        return head->next->minNum;
    }
};

void test() {
    MinStack *s = new MinStack();
    s->push(20);
    s->push(10);
    s->push(30);
    s->push(5);
    s->pop();
    cout << "栈中最小元素是：" << s->getMin() << endl;
}

int main() {
    test();
    return 0;
}