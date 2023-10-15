/*
 * https://leetcode.cn/problems/valid-anagram/
 * */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution1 {
public:
    bool isAnagram(string s, string t) {
        vector<int> Result(26, 0);
        for (char i: s) {
            Result[i - 'a']++;   // Result[0]~Result[25]分别记录字符串s中a~z出现的次数
        }

        for (char i: t) {
            Result[i - 'a']--;   // 字符串t中出现过一次，Result[i]就减一次
        }

        for (int i = 0; i < 26; ++i) {
            // Result数组全为0时，说明字符串s和t中字母出现次数相同
            if (Result[i] != 0) return false;
        }
        return true;
    }
};

class Solution_set {
public:
    bool isAnagram(string s, string t) {
        /*
         * unordered_set<> 不允许出现重复元素
         * unordered_multiset<> 允许出现重复元素
         * */
        unordered_multiset<char> s1;
        unordered_multiset<char> t1;

        for (char i: s) {
            s1.insert(i);
        }
        for (char i: t) {
            t1.insert(i);
        }

        bool flag;

        for (int i = 0; i < 26; ++i) {
            char cc = 'a' + i;
            if (s1.count(cc) == t1.count(cc)) flag = true;
            else {
                flag = false;
                break;
            }
        }

        return flag;
    }
};


int main() {
    string s = "aaaa";
    string t = "aaaa";

    Solution1 s1;
    Solution_set solution;

    cout << s1.isAnagram(s, t) << endl;

    return 0;
}