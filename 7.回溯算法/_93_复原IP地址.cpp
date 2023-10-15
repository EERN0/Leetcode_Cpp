/*
 * https://leetcode.cn/problems/restore-ip-addresses/
 * */
#include <vector>
#include <string>

using namespace std;

// 自己写的，复杂了点，和lc131分割回文串差不多
class Solution {
public:
    vector<string> path;
    vector<string> result;

    void backtracking(const string &s, int startIndex) {
        // 终止条件
        if (path.size() == 4) {
            // path的格式为：{"255","255","11","135"}
            string string1;
            for (int i = 0; i < 4; ++i) {
                if (i <= 2) {
                    string1.append(path[i]).append(".");
                }
                else {  // i==3时，最后一个不加.
                    string1.append(path[i]);
                }
            }

            // 收集结果
            if (string1.size() == s.size() + 3) {
                result.push_back(string1);
            }
        }

        // 单层搜索逻辑
        for (int i = startIndex; i < s.size(); ++i) {
            if (isIpNum(s, startIndex, i)) {    // 符合ip地址的要求
                path.push_back(s.substr(startIndex, i - startIndex + 1));
            }
            else {
                continue;
            }

            // 递归搜索，相当于多层for
            backtracking(s, i + 1);

            // 回溯撤销操作
            path.pop_back();
        }
    }

    // 判断是否符合ip地址的要求
    bool isIpNum(const string &s, int left, int right) {
        string str = s.substr(left, right - left + 1);
        int ipNum = atoi(str.c_str());

        if (str.size() >= 2) {  // 012不符合ip地址要求，0符合ip地址要求
            if (str[0] == '0') return false;
        }

        if (ipNum >= 0 && ipNum <= 255) {
            return true;
        }

        return false;
    }

    vector<string> restoreIpAddresses(string s) {
        backtracking(s, 0);
        return result;
    }
};