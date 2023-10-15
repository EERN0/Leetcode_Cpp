// Created by caokang on 2023/5/13.
// https://leetcode.cn/problems/palindrome-number/
#include <string>
#include <algorithm>

using namespace std;

// 逆置x后面一半数字，存到reverse中
// eg：x=12321 --> x=12, reverse=123
class Solution2 {
public:
    bool isPalindrome(int x) {
        // if (x < 0) return false;  // 过不了x=10的情况

        // 负数肯定不是回文串
        // x%10为0，说明最后一位是0，若是回文，必须第一位也是0，只用x==0才符合
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reverse = 0;
        while (x > reverse) {
            reverse = reverse * 10 + x % 10;
            x = x / 10;
        }

        if (x == reverse || x == reverse / 10) return true;
        else return false;
    }
};

// 最直接的思路，把数字转换为字符串，再判断
class Solution1 {
public:
    bool isPalindrome(int x) {
        string str;
        int temp = x;
        // 负数不可能是回文串
        if (x < 0) return false;

        while (temp) {
            str += (temp % 10 + '0');   // 加上'0'才可以变成数字字符，不是减'0'
            temp = temp / 10;           // temp要不断除以10，减掉最后1位
        }

        // 也不用逆序了，是回文数正、逆序都一样
        reverse(str.begin(), str.end());

        int left = 0, right = str.size() - 1;
        while (left < right) {
            if (str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution1 solution1;
    int x = -121;
    solution1.isPalindrome(x);
}