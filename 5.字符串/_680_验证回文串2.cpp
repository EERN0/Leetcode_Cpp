// Created by caokang on 2023/5/13.
// https://leetcode.cn/problems/valid-palindrome-ii/
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 判断是否为回文串
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++, right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        if (s.size() <= 2) return true;
        int left = 0, right = s.size() - 1;

        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            }
            else {   // s[left] != s[right]
                // 先删除左边元素、先删除右边元素这两种情况都进行判断，不会因为先删除了左边元素而直接判断是不是回文串
                // 可以处理这种情况 s = "cupxpucu"，先删除左边的c不回文，先删除右边的u回文
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
        }
        return true;
    }
};

//// 错误
//// 优先考虑了删除左边元素的情况，当左右都可以删除的时候，无法处理
//// s="cupxpucu";    删除左边第一个，false；删除右边第一个，true

//class Solution {
//public:
//    bool validPalindrome(string s) {
//        if (s.size() <= 2) return true;
//        int count = 0;  // 统计删了几次,只能删除1次
//        int left = 0, right = s.size() - 1;
//
//        while (left < right) {
//            // 优先考虑了删除左边元素的情况，当左右都可以删除的时候，无法处理
//            // s="cupxpucu";    删除左边第一个，false；删除右边第一个，true
//            if ((s[left] != s[right])) {
//                // 只能删除1次元素
//                if (s[left + 1] == s[right]) {   // s = "cbaab"，删除第一个c
//                    left++; // 相当于删除s[left]这个元素
//                    count++;
//                }
//                else if (s[left] == s[right - 1]) {   // s = "baabc"，删除最后一个c
//                    right--;
//                    count++;
//                }
//                else {  // 删过1个元素了，或者删了元素也构不成回文串
//                    return false;
//                }
//            }
//            else if (s[left] == s[right]) {
//                left++;
//                right--;
//            }
//        }
//
//        if (count <= 1) return true;
//        else return false;
//    }
//};

int main() {
    Solution solution;
    string s = "cupxpucu";

    solution.validPalindrome(s);
}