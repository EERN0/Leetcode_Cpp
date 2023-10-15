/*
 * https://leetcode.cn/problems/palindrome-partitioning/
 * */
#include <string>
#include <vector>

using namespace std;

/*
 * startIndex是切割线
 * 切割字串的范围[startIndex, i]，用这个范围去判断是否回文
 * 递归搜索终止条件：startIndex搜索到末尾了
 * */
class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;    // 存放已经回文的子串


    void backtracking(const string &s, int startIndex) {
        // 递归终止条件：startIndex切割到末尾了
        if (startIndex >= s.size()) {   // startIndex==size-1时，再执行backtracking(s, i + 1)，startIndex就等于size
            result.push_back(path);
            return;
        }

        // 单层递归搜索逻辑
        for (int i = startIndex; i < s.size(); ++i) {
            if (palindrome(s, startIndex, i)) { // 是回文串
                path.push_back(s.substr(startIndex, i - startIndex + 1));   // 把回文子串装入path
            }
            else {  // 不是回文的子串，跳过
                continue;
            }

            // 递归
            backtracking(s, i + 1);

            // 回溯，撤销操作
            path.pop_back();
        }
    }

    // 判断是不是回文串
    bool palindrome(string s, int left, int right) {
        if (s.size() < 2) return true;

        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }


    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return result;
    }
};