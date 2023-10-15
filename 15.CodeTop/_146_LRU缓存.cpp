// https://leetcode.cn/problems/lru-cache/
#include <iostream>
#include <unordered_map>

using namespace std;

// L-1-2-3-R
class LRUCache {
public:
    struct Node {
        int key, val;
        Node *pre, *next;

        Node(int k, int v) : key(k), val(v), pre(nullptr), next(nullptr) {}
    };

    unordered_map<int, Node *> umap; // map存key和
    Node *L, *R;    // 双向链表的左右虚拟头节点

    int n;

    LRUCache(int capacity) {
        n = capacity;
        // 初始化操作
        L = new Node(-1, -1);
        R = new Node(-1, -1);
        // 双向链表
        L->next = R;
        R->pre = L;
    }

    int get(int key) {
        // 访问了umap中的key，把key移到最右边
        if (umap.count(key)) {
            Node *node = umap[key];  // 通过key取出val(umap的val是Node*)
            remove(node);   // 从链表中移除该节点
            insert(node->key, node->val);   // 在链表的最右端插入该节点
            return node->val;
        }
        else {    // key不在哈希表umap中，返回-1
            return -1;
        }
    }

    void put(int key, int value) {
        // key在哈希表中
        if (umap.count(key)) {
            Node *node = umap[key];
            remove(node);
            insert(key, value);
        }
        else {
            // key不在哈希表中，是一个全新的元素，要插入而且要判断是否超过了capacity
            if (umap.size() == n) { // 双向链表满了，把最左边的元素删掉
                auto node = L->next;
                remove(node);   // 删掉最左边的元素
                insert(key, value);
            }
            else {    // 链表容量没满，将node节点插到链表的最右边
                insert(key, value);
            }
        }
    }

    // 双向链表移除节点node, 链表删除node、哈希表删除key
    void remove(Node *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        umap.erase(node->key);

//        delete (node);
    }

    // 双向链表插入元素(右插), 同时操作链表和哈希表
    void insert(int key, int val) {
        auto node = new Node(key, val);
        R->pre->next = node;
        node->next = R;
        node->pre = R->pre;
        R->pre = node;

        umap[key] = node;
    }

    // 打印输出链表, 用于测试
    void printListNode(Node *head) {
        while (head != NULL) {
            if (head->next != NULL) {
                cout << head->val << "<->";
            }
            else {
                cout << head->val << endl;
            }
            head = head->next;
        }
    }
};

int main() {

    LRUCache *obj = new LRUCache(2);
    obj->put(2, 1);
    obj->put(2, 2);
    int param_1 = obj->get(2);
    cout << param_1 << endl;

    obj->put(1, 1);
    obj->put(4, 1);
    int param_2 = obj->get(2);

    obj->printListNode(obj->L);

    cout << param_2 << endl;

    return 0;
}