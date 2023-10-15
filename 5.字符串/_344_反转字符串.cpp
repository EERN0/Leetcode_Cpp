/*
 * https://leetcode.cn/problems/reverse-string/
 * */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char> &s) {
        if (s.size() == 0 || s.size() == 1) return;

        char temp;
        for (int i = 0; i < s.size() / 2; ++i) {
            temp = s[i];
            s[i] = s[s.size() - 1 - i];
            s[s.size() - 1 - i] = temp;
        }
    }

    void reverseString2(vector<char> &s) {
        int n = s.size();
        // left==right就停止，最中间的不用处理
        for (int left = 0, right = n - 1; left < right; left++, right--) {
            swap(s[left], s[right]);
        }
    }
};

int main() {
    vector<char> c = {'h', 'e', 'l', 'l', 'o'};
    Solution s;
    s.reverseString2(c);

    for (auto i: c) {
        cout << i << " ";
    }

    return 0;
}