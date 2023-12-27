// https://leetcode.cn/problems/copy-list-with-random-pointer/
// Created by caokang on 2023/10/18.
#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution138 {
public:
    Node *copyRandomList(Node *head) {
        if (!head) return nullptr;

        unordered_map<Node *, Node *> umap;
        Node *cur = head;
        // [#1]哈希表把旧-新链表节点映射一波
        while (cur) {
            umap[cur] = new Node(cur->val);
            cur = cur->next;
        }
        // [#2]连接新节点的next域、random域
        cur = head;
        while (cur) {
            // 1.umap[cur]是当前节点对应的新节点。新节点umap[cur]的next域指向新节点umap[cur->next]
            umap[cur]->next = umap[cur->next];
            // 2.新节点的random域
            umap[cur]->random = umap[cur->random];
            cur = cur->next;
        }
        return umap[head];
    }
};