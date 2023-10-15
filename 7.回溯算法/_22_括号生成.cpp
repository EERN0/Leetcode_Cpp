/*
 * https://leetcode.cn/problems/generate-parentheses/
 * */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> result;
    string path;

    void backtracking(int left, int right) { // left、right表示左、右括号还有几个可用
        // 终止条件：左右可用括号数为0
        if (left == 0 && right == 0) {
            // 收集结果
            result.push_back(path);
        }

        // 先上左括号，再上右括号
        if (left > 0) {  // 左括号还有可用的
            path.push_back('(');
            backtracking(left - 1, right);
            // 回溯操作，撤销处理结果
            path.pop_back();
        }

        if (right > left) { // 可用的右括号数大于左括号
            path.push_back(')');
            backtracking(left, right - 1);
            // 回溯操作，撤销处理结果
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        backtracking(n, n);     // 可用的左右括号数均为n
        return result;
    }
};

int main() {
    Solution s;
    vector<string> res = s.generateParenthesis(3);

    for (const auto &o: res) {
        cout << o << " ";
    }
    // ((())) (()()) (())() ()(()) ()()()

    return 0;
}
