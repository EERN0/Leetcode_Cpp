/*
 * https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
 *
 * advance: _1209_删除字符串中的所有相邻重复项II (没写)
 * https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string-ii/
 * */

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> mystack;
        // 扫描一遍s
        for (int i = 0; i < s.size(); ++i) {

            if (mystack.empty() || s[i] != mystack.top()) {
                mystack.push(s[i]);
            }
            else if (!mystack.empty() && s[i] == mystack.top()) {
                // s[i]==mystack.top(), 说明在s中是相邻重复的字符, 从栈中删除
                mystack.pop();
            }
        }

        string result = "";
        while (!mystack.empty()) {
            result += mystack.top();    // 拼接字符串
            mystack.pop();
        }

        // 头文件algorithm
        reverse(result.begin(), result.end());

        return result;
    }
};


// 字符串模拟栈
class Solution2 {
public:
    string removeDuplicates(string s) {
        string result = "";

        // 字符串result的尾部作为栈顶，返回result
        for (char c: s) {
            if (result.empty() || c != result.back()) {
                result.push_back(c);
            }
            else {  // 栈里面有元素，且栈顶元素和当前扫描的字符c一样，弹出该元素
                result.pop_back();
            }
        }

        return result;
    }
};

int main() {
    string s = "abbaca";
    Solution solution;
    Solution2 solution2;

    string res = solution2.removeDuplicates(s);

    cout << res << endl;

    return 0;
}