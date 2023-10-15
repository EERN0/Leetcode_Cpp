// https://leetcode.cn/problems/roman-to-integer/
// Created by kang on 2023/8/20.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution13 {
public:
    int romanToInt(string s) {
        // 映射表，通过key，拿出value
        unordered_map<char, int> umap = {{'I', 1},
                                         {'V', 5},
                                         {'X', 10},
                                         {'L', 50},
                                         {'C', 100},
                                         {'D', 500},
                                         {'M', 1000}};

        // 一般罗马数是左边大于右边的，
        // 如果一直满足左边大于右边，即 LXVI，则表示：50+10+5+1=66；
        // 如果左边的小于右边的，表示要减去左边的数，例如，XIV，由于I对应的是1，V对应的是5，表示 10-1+5=14

        int sum = 0;
        // 遍历罗马字符
        for (int i = 0; i < s.size(); ++i) {
            if (i + 1 < s.size() && umap[s[i]] < umap[s[i + 1]]) {
                // 左边的字符对应的值，小于右边字符对应的值。要减去左边的值
                sum -= umap[s[i]];
            }
            else {  // 左边字符大于右边字符，加上左边字符就行
                sum += umap[s[i]];
            }
        }

        return sum;
    }
};