// https://leetcode.cn/problems/lfu-cache/
// Created by caokang on 2023/11/16.
// LFU: 最不经常使用
#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int freq = 1, key, val;
    Node *prev, *next;

    Node(int key = 0, int value = 0) : key(key), val(value) {}
};

class LFUCache {
public:
    LFUCache(int capacity) {
        n = capacity;
    }

    int get(int key) {
        Node *node = getNodeByKey(key);
        return node == nullptr ? -1 : node->val;
    }

    void put(int key, int value) {
        Node *node = getNodeByKey(key);
        if (node) {
            node->val = value;
            return;
        }
        // 节点中不存在这个key，且满了，要移除freq最小且最靠右的节点
        if (key_map.size() == n) {
            Node *dummy = freq_map[min_freq];
            Node *backNode = dummy->prev;   // 采用的是头插法，移除同频次freq最右的节点
            key_map.erase(backNode->key);   // key_map上要移除这个key
            remove(backNode);        // freq_map[min_freq]的链表上移除这个节点
            if (dummy->next == dummy) {     // 若移除节点后只有一个dummy了，删掉空链表
                freq_map.erase(min_freq);
                delete dummy;
            }

            delete backNode;    // 释放节点空间
        }
        // 添加新节点，freq设为1，addHead()只处理了freq_map，没处理key_map这个表
        node = new Node(key, value);
        min_freq = 1;
        addHead(1, node);
        key_map[key] = node;
    }

public:
    int min_freq;   //最小频率
    int n;   //容量

    unordered_map<int, Node *> freq_map;      //以频率freq为索引,每一个freq对应一条双向链表
    unordered_map<int, Node *> key_map;       //以键值key为索引,索引指向双向链表节点(索引值等于节点的key)

    // freq_map下每一个索引都至少有一个dummy虚拟头节点
    Node *newList() {
        Node *dummy = new Node(-1, -1);
        dummy->prev = dummy;
        dummy->next = dummy;
        return dummy;
    }

    void remove(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
//        delete node;
    }

    void addHead(int freq, Node *node) {
        if (node == nullptr) return;
        auto it = freq_map.find(freq);
        if (it == freq_map.end()) {     // freq_map[]中没有索引freq及其对应的链表
            // 创建一条链表
            Node *dummy = newList();
            dummy->next = node;
            node->prev = dummy;
            dummy->prev = node;
            node->next = dummy;
            // freq_map[freq]连接上链表
            freq_map[freq] = dummy;
        }
        else {  // freq_map中含有索引freq和对应的链表
            Node *dummy = it->second;
            // 头插法
            node->prev = dummy;
            node->next = dummy->next;
            dummy->next->prev = node;
            dummy->next = node;
        }
    }

    // 根据key查询节点，这个key的频次+1，移动到freq_map[freq]的下一条链表freq_map[freq+1]
    Node *getNodeByKey(int key) {
        auto it = key_map.find(key);
        if (it == key_map.end()) {  // 节点中没有这个key
            return nullptr;
        }
        // 节点中有这个key，找到这个节点及其所在的双向链表，从原链表移除该节点，加入到freq_map[freq+1]对应的双向链表中
        Node *node = it->second;
//        int freq = node->freq;
//        int value = node->val;
        // 找到这个节点所在的双向链表的dummy节点
        auto dummy = freq_map[node->freq];
        // 在原先的freq索引对应的链表中移除这个节点
        remove(node);
        if (dummy->next == dummy) {     // 移除node节点后，若双向链表只剩下dummy，直接删掉这条链表
            freq_map.erase(node->freq);
            delete dummy;

            if (min_freq == node->freq) min_freq++;   // freq查过一次，下面要加1了。最小频次也+1
        }
        addHead(++node->freq, node);
        return node;
    }
};

int main() {
//    LFUCache *obj = new LFUCache(2);
//
//    obj->put(1, 1);
//    obj->put(2, 2);
//    cout << obj->get(1) << endl;
//
//    obj->put(3, 3);
//    cout << obj->get(2) << endl;
//
//    cout << obj->get(3) << endl;
//
//    obj->put(4, 4);
//    cout << obj->get(1) << endl;
//    cout << obj->get(3) << endl;
//    cout << obj->get(4) << endl;

    LFUCache *obj = new LFUCache(3);

    obj->put(2, 2);
    obj->put(1, 1);
    cout << obj->get(2) << endl;
    cout << obj->get(1) << endl;
    cout << obj->get(2) << endl;

    obj->put(3, 3);
    obj->put(4, 4);
    cout << obj->get(3) << endl;
    cout << obj->get(2) << endl;
    cout << obj->get(1) << endl;
    cout << obj->get(4) << endl;

}