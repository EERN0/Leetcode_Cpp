// https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/
// Created by caokang on 2023/10/5.

#include <string>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstring>
#include "二叉树结构体.hpp"

using namespace std;

// 层序遍历写的，巨离谱，主要是没有split()来分割字符串，要判断负数、多位数字，就nm离谱

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr) return "[]";
        string data = "[";
        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            if (node != nullptr) {
                data.append(to_string(node->val)).append(",");
                que.push(node->left);
                que.push(node->right);
            }
            else {  // node为null
                data.append("null").append(",");
            }
        }
        // 此时 data=[1,2,3,null,null,4,5,null,null,null,null,
        data.erase(data.size() - 1);
        data.append("]");   // data=[1,2,3,null,null,4,5,null,null,null,null]
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data == "[]") return nullptr;
        vector<int> vals;    // 存二叉树节点值的，null节点用INT16_MIN表示。    下面那种方法是数组存的string
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] == '[' || data[i] == ',' || data[i] == ']') continue;
            else if (isdigit(data[i])) {    // 是数字，要有处理多位数字的逻辑
                int start = i;
                while (i + 1 < data.size() && isdigit(data[i + 1])) {
                    i++;
                } // 退出while，data[i+1]不是数字了，但是data[i]是数字
                string numStr = data.substr(start, i - start + 1);
                vals.push_back(stoi(numStr));
            }
            else if (data[i] == '-') {  // 处理节点值是负数的情况，负数也要处理多位数字
                i++;    // 跳过负号
                int start = i;
                while (i + 1 < data.size() && isdigit(data[i + 1])) {
                    i++;
                } // 退出while，data[i+1]不是数字了，但是data[i]是数字
                string numStr = "-";
                numStr.append(data.substr(start, i - start + 1));
                vals.push_back(stoi(numStr));
            }
            else {  // 遇到了null
                i = i + 3;      // 直接跳到最后的l，下一轮i+1后就跳过这个null了
                vals.push_back(INT16_MIN);
            }
        }

        // vals = [1,2,3,INT16_MIN,INT16_MIN,4,5,INT16_MIN,INT16_MIN,INT16_MIN,INT16_MIN]
        queue<TreeNode *> que;
        TreeNode *root = new TreeNode(vals[0]);
        que.push(root);
        int i = 1;
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            if (vals[i] != INT16_MIN) {
                node->left = new TreeNode(vals[i]);
                que.push(node->left);
            }
            i++;

            if (vals[i] != INT16_MIN) {
                node->right = new TreeNode(vals[i]);
                que.push(node->right);
            }
            i++;
        }
        return root;
    }
};

class Codec2 {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (root == nullptr) return "[]";
        queue<TreeNode *> que;
        que.push(root);
        string data = "[";

        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            if (node != nullptr) {
                data.append(to_string(node->val)).append(",");
                que.push(node->left);
                que.push(node->right);
            }
            else {  // node为null
                data.append("null").append(",");
            }
        }
        data.erase(data.size() - 1);    // 去掉最后面的, [1,2,3,null,null,4,5,null,null,null,null
        data.append("]");                 // [1,2,3,null,null,4,5,null,null,null,null]
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data == "[]" || data == "[null]") return nullptr;

        vector<string> val;         // 存字符串的数组，[1,2,3,null,null,4,5,null,null,null,null]
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] == '[' || data[i] == ']' || data[i] == ',') continue;
            else if (data[i] == '-') {      // 遇到了负数！！要特别判断
                string minus = "-";
                i++;    // 跳过负号
                int start = i;
                while (i + 1 < data.size() && isdigit(data[i + 1])) {   // 多位数字
                    i++;
                }   // 退出while, data[i+1]不是数字字符，data[i]是数字字符
                minus.append(data.substr(start, i - start + 1)); // 负数
                val.push_back(minus);
            }
            else if (isdigit(data[i])) {    // 多位数的情况
                int start = i;
                while (i + 1 < data.size() && isdigit(data[i + 1])) {
                    i++;
                }   // 退出while, data[i+1]不是数字字符，data[i]是数字字符
                val.push_back(data.substr(start, i - start + 1));
            }
            else {  // 碰到了null，直接把null装入字符串数组中
                // i要跳过这个null
                int cnt = 4;
                while (cnt--) {
                    i++;
                }
                val.push_back("null");
            }
        }

        // val = [1,2,3,null,null,4,5,null,null,null,null]      vector<string>
        TreeNode *root = new TreeNode(stoi(val[0]));
        queue<TreeNode *> que;
        que.push(root);

        int i = 1;  // 根节点已经放入队列了
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            if (val[i] != "null") {
                node->left = new TreeNode(stoi(val[i]));
                que.push(node->left);
            }
            i++;

            if (val[i] != "null") {
                node->right = new TreeNode(stoi(val[i]));
                que.push(node->right);
            }
            i++;
        }
        return root;
    }
};

int main() {
    TreeNode *node4 = new TreeNode(5, nullptr, nullptr);
    TreeNode *node3 = new TreeNode(4, nullptr, nullptr);
    TreeNode *node2 = new TreeNode(-33, node3, node4);
    TreeNode *node1 = new TreeNode(-22, nullptr, nullptr);
    TreeNode *node0 = new TreeNode(1, node1, node2);

    Codec ser, deser;
    string data = ser.serialize(node0);
    cout << data << endl;

    deser.deserialize(data);

//    int res = stoi("-100");
//    cout << res;    // -100

}