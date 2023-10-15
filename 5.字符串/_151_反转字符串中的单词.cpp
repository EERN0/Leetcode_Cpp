/*
 * https://leetcode.cn/problems/reverse-words-in-a-string/
 * */
#include <iostream>
#include <string>

using namespace std;

// 找空格类似 lc27 移除元素
class Solution {
public:
    string reverseWords(string s) {
        // 2.去除多余的空格
        removeSpace(s);
        // 1.将字符串s整体逆置
        reverse(s, 0, s.size() - 1);

        // 3.将每个单词逆置过来
        int start = 0;
        for (int i = 0; i < s.size(); i++) {
            // 到达空格或者串尾，说明一个单词结束，进行翻转
            if (s[i + 1] == ' ' || i == s.size() - 1) {
                reverse(s, start, i);
                start = i + 2;
            }
        }
        return s;
    }

    // 去除所有空格并在相邻单词之间添加空格, 快慢指针, 原地操作
    void removeSpace(string &s) {
        int fast = 0, slow = 0;
        for (; fast < s.size(); fast++) {
            // 遇到非空格就处理，即删除多余的空格
            if (s[fast] != ' ') {
                // 手动给单词之间添加空格。slow!=0说明不是第一个单词，需要在单词前添加空格
                if (slow != 0) s[slow++] = ' ';

                while (fast < s.size() && s[fast] != ' ') {
                    s[slow++] = s[fast++];
                }
            }
        }
        // slow的大小即为去除多余空格后字符串s的长度
        s.resize(slow);
    }

    // 反转字符串，传入string &s, 左闭右闭区间
    void reverse(string &s, int start, int end) {
        for (int left = start, right = end; left < right; left++, right--) {
            swap(s[left], s[right]);
        }
    }
};

int main() {
    string s = "  hello world  ";
    Solution solution;
    string res = solution.reverseWords(s);

    for (auto c: res) {
        cout << c;
    }

    return 0;
}