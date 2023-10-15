/*
 * https://leetcode.cn/problems/reverse-string-ii/
 * */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2 * k) {
            // 每2k个字符，逆置前k个字符，reverse()函数-左闭右闭
            if (i + k <= s.size()) {
                reverse(s, i, i + k - 1);
            }
            else {
                reverse(s, i, s.size() - 1);
            }
        }
        return s;
    }

    // 逆置string字符串，必须传入引用string &s
    static void reverse(string &s, int start, int end) {
//        for (int i = start; i <= (start + end) / 2; ++i) {
//            swap(s[i], s[start + end - i]);
//        }

        for (int left = start, right = end; left < right; left++, right--) {
            swap(s[left], s[right]);
        }
    }
};

int main() {
    string s1 = "abcd";
    string res;

    Solution solution;
    res = solution.reverseStr(s1, 4);

    for (auto c: res) {
        cout << c << " ";
    }
    return 0;
}