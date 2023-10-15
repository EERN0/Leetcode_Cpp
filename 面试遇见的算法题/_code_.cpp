// 字节面试题，出现过多次
// Created by caokang on 2023/7/30.
/*
 * 返回由数组A中元素组成的小于target的最大数
 * eg：A={1,2,4,9}, target=2533, 返回2499
 * */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;

    // 把数组元素转换为数字
    int array2num(vector<int> &nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum = sum * 10 + nums[i];
        }
        return sum;
    }

    // 回溯模板
    void backtracking(vector<int> &A, int target, int targetLen, vector<bool> &used) {
        // 记录比target小1位的数，以及 位数相等但是小于target的数
        if (path.size() == targetLen) {     // 加上判断条件 array2num(path)<target会报错
            result.push_back(path);
            return;
        }

        for (int i = 0; i < A.size(); ++i) {
            // 树层去重
            if (i > 0 && A[i] == A[i - 1] && !used[i - 1]) {
                continue;
            }
            else {
                path.push_back(A[i]);
                used[i] = true;

                backtracking(A, target, targetLen, used);

                path.pop_back();
                used[i] = false;
            }
        }
    }

    int maxNum(vector<int> &A, int target) {
        // 先把A从小到大排序
        sort(A.begin(), A.end());
        // 把target存到数组中，获取target的位数
        int copy = target;
        vector<int> nums;
        while (copy) {
            nums.push_back(copy % 10);
            copy /= 10;
        }
        reverse(nums.begin(), nums.end());
        int len = nums.size();

        vector<bool> used(A.size(), false);
        backtracking(A, target, len, used);

        // 打印result数组
//        for (auto v: result) {
//            cout << array2num(v) << " ";
//        }

        vector<int> ans;
        for (auto &num: result) {
            if (array2num(num) < target) {
                ans.push_back(array2num(num));
            }
        }

        // 打印ans数组
        cout << "满足所有小于target的同位数：" << endl;
        for (auto &n: ans) {
            cout << n << " ";
        }
        cout << endl << "-------" << endl;

        // ans为空，说明相同位数已经没有小于target的了，选择数组A中最大的组成少1位数的
        if (ans.empty()) {
            cout << "ans is empty" << endl;
            int n = len - 1;    // len是target的长度，不是A的长度
            while (n--) {
                ans.push_back(A.back());
            }
            cout << "array2num(ans)==" << array2num(ans) << endl;
            return array2num(ans);
        }
        else {
            // ans数组是从小到大的4位数且均小于target，返回最大的那个数
            return ans.back();
        }
    }
};


int main() {
    vector<int> A = {2, 4, 9};
    int target = 244131;
    Solution solution;
    int x = solution.maxNum(A, target);
    cout << x << endl;
    return 0;
}