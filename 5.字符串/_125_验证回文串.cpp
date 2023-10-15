// Created by caokang on 2023/5/11.
// https://leetcode.cn/problems/valid-palindrome/
#include <string>

using namespace std;

class Solution {
public:
    bool isNumOrChar(char ch) {
        ch = tolower(ch);    // 转换为小写
        if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) { // 是字母，或者数字
            return true;
        }
        else return false;
    }

    bool isPalindrome(string s) {
        if (s.size() <= 1) return true;
        // 全转换为小写
        for (int i = 0; i < s.size(); ++i) {
            s[i] = tolower(s[i]);
        }

        int left = 0, right = s.size() - 1;
        for (; left < right; left++, right--) {
            // 跳过非字母、数字的字符
            while ((left < right) && !isNumOrChar(s[left])) left++;
            while ((left < right) && !isNumOrChar(s[right])) right--;

            // s[left]和s[right]是字母或数字了，比较s[left]和s[right]是否相同
            if (s[left] != s[right]) return false;
        }
        return true;
    }
};