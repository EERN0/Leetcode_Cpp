/*
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
 * */
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> keymap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // 数字到字母的映射
    string path;
    vector<string> result;

    // index表示当前遍历到字符串digits哪一个位置了
    void backtracking(const string &digits, int index) {
        // 搜索结束，index指向digits最后一个元素时，还要处理，指向最后一个的下一个才表示处理结束
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }

        int k = digits[index] - '0';    // char - '0'表示和0的距离，eg: char(2) - '0' == 2
        string letters = keymap[k];
        for (int i = 0; i < letters.size(); ++i) {

            path.push_back(letters[i]);

            backtracking(digits, index + 1);

            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        backtracking(digits, 0);
        return result;
    }
};