// Created by caokang on 2023/4/28.
// https://leetcode.cn/problems/minimum-window-substring/
// 滑动窗口
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // smap是滑动窗口[let,right]中字符char的出现次数
        unordered_map<char, int> smap, tmap;

        for (const auto &o: t) {    // 把字符串t的字符和出现的次数记录到tmap中
            tmap[o]++;
        }
        int left = 0, right = 0;    // 控制滑动窗口的大小
        int cnt = 0;                // 符合要求的字符数
        string res = {};

        for (; right < s.size(); ++right) {
            ++smap[s[right]];

            // tmap中字符出现的次数大于等于smap中字符出现的次数
            // 说明刚添加到smap中的字符在t中出现过，所以符合要求的字符数加1
            if (tmap[s[right]] >= smap[s[right]]) {
                ++cnt;
            }

            // 缩小滑动窗口[left, right]
            // smap中，s[left]出现的次数大于该字符在t中出现的次数，将smap中该字符的出现次数减1，left右移
            while (left < right && smap[s[left]] > tmap[s[left]]) {
                --smap[s[left]];
                ++left;
            }

            // 有效字符数等于t.size，说明滑动窗口的子串可以覆盖t
            if (cnt == t.size()) {
                if (res.empty() || res.size() > right - left + 1) {
                    res = s.substr(left, right - left + 1);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    string s = "ADOBECODEBANC", t = "ABC";
    string res = solution.minWindow(s, t);

    for (auto o: res) {
        cout << o;
    }

    return 0;
}