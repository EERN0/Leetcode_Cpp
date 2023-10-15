// https://leetcode.cn/problems/string-compression/
// Created by caokang on 2023/9/17.
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

// 原地操作
//class Solution443 {
//public:
//    int compress(vector<char> &chars) {
//        int write = 0;
//        int left = 0;
//
//        for (int read = 0; read < chars.size(); ++read) {
//            chars[write++] = chars[read];
//            // read是连续重复子串的最后一个字符
//            if (read == chars.size() - 1 || chars[read] != chars[read + 1]) {
//                int len = read - left + 1;      // 计算重复字符的长度
//                // 连续字符长度大于1，记录下这个长度
//                if (len > 1) {
//                    chars[read] = len + '0';
//                }
//
//            }
//        }
//    }
//};


class Solution {
public:
    int compress(vector<char> &chars) {
        int n = chars.size();
        int write = 0, left = 0;
        for (int read = 0; read < n; read++) {
            if (read == n - 1 || chars[read] != chars[read + 1]) {
                chars[write++] = chars[read];
                int num = read - left + 1;
                if (num > 1) {
                    int anchor = write;
                    while (num > 0) {
                        chars[write++] = num % 10 + '0';
                        num /= 10;
                    }
                    reverse(&chars[anchor], &chars[write]);
                }
                left = read + 1;
            }
        }
        return write;
    }
};

// 非原地操作
class Solution_xx {
public:
    int compress(vector<char> &chars) {
        unordered_map<char, int> umap;
        for (const char &c: chars) {
            umap[c]++;
        }
        vector<char> result;
        auto it = umap.begin();
        for (; it != umap.end(); it++) {
            result.push_back(it->first);
            result.push_back(it->second);;
//            cout << it->first << " " << it->second << ";";
        }
        return result.size();
    }
};

int main() {
    Solution s;
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int res = s.compress(chars);
    cout << res << endl;
}