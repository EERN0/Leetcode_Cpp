/*
 * https://leetcode.cn/problems/combinations/
 * */
#include <vector>

using namespace std;

// 没剪枝
class Solution {
public:
    vector<int> path;
    vector<vector<int>> result;
public:
    void backtracking(int n, int k, int startIndex) {   // startIndex防止出现重复的组合
        // 递归终止条件，收集了k个组合数
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        // 单层搜索的逻辑
        for (int i = startIndex; i <= n; i++) {
            path.push_back(i);  // 收集结果

            // 递归
            backtracking(n, k, i + 1); // 下一层递归的起始位置是i+1

            path.pop_back();    // 回溯操作，撤销处理结果
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};

// 剪枝，都在backtracking()的for循环中进行
class Solution2 {
public:
    vector<int> path;
    vector<vector<int>> result;

    void backtracking(int n, int k, int startIndex) {   // startIndex防止出现重复的组合
        // 递归终止条件，收集了k个组合数
        if (path.size() == k) {
            result.push_back(path);
            return;
        }

        // 剪枝，一共要选k个，path.size()是已经选取元素的个数，所以还要选 k-path.size() 个元素
        // 下标最多从 n-(k-path.size)+1 开始，才能选足k个元素。例如，n=4，k=3，path中没有元素，那么下标i最多可以从2开始，能选出2-3-4满足条件
        for (int i = startIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);  // 收集结果

            // 递归
            backtracking(n, k, i + 1); // 下一层递归的起始位置是i+1

            path.pop_back();    // 回溯操作，撤销处理结果
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> res = s.combine(4, 2);

    return 0;
}