// https://leetcode.cn/problems/longest-common-prefix/
// Created by caokang on 2023/10/2.
#include <string>
#include <vector>

using namespace std;

class Solution14 {
public:
    // 获取两字符串的公共部分
    string commonPrefix(string str1, string str2) {
        int length = min(str1.size(), str2.size());
        int index = 0;
        while (index < length && str1[index] == str2[index]) {  // 一直往后扫描匹配
            index++;
        }

        return str1.substr(0, index);
    }

    // 每两个字符串进行比较，取出公共的部分
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i) {
            // 每两个字符串取出公共前缀，只要有一组公共前缀为""，最长公共前缀一定为""
            prefix = commonPrefix(prefix, strs[i]);
            if (prefix == "") {
                return "";
            }
        }
        return prefix;
    }
};