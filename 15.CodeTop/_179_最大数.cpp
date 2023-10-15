// https://leetcode.cn/problems/largest-number/
// Created by caokang on 2023/10/3.
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution179 {
public:
    string largestNumber(vector<int> &nums) {
        vector<string> strs;
        for (const int &num: nums) {
            strs.push_back(to_string(num));     // to_string(): 把其他类型转为字符串
        }
        // 自定义比较函数，规则：拼接后的字符串，按字典序，大的在左，小的在右。3-30 > 30-3，则3在前，30在后
        sort(strs.begin(), strs.end(), [](string &x, string &y) -> bool { return x + y > y + x; });

        // nums=[0,0]时，结果要是"0",不能是"00"
        if (strs[0] == "0") {   // 排序完后，大的在左，如果最左边的还是0，说明nums是全0数组
            return "0";
        }

        string result;
        for (const string &str: strs) {
            result.append(str);
        }
        return result;
    }
};


int main() {
    vector<int> nums = {3, 30, 34, 5, 9};
    Solution179 solution179;
    string res = solution179.largestNumber(nums);
    cout << res << endl;
}