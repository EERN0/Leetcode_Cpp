// https://leetcode.cn/problems/subarray-sum-equals-k/description/
// Created by kang on 2023/8/24.
#include <vector>
#include <unordered_map>

using namespace std;

// 下次记得看笔记
class Solution560 {
public:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> umap;
        umap[0] = 1;
        int pre = 0;        // 前缀和
        int cnt = 0;

        for (int i = 0; i < nums.size(); ++i) {
            pre += nums[i];
            if (umap.count(pre - k)) {
                cnt += umap[pre - k];
            }
            umap[pre]++;
        }
        return cnt;
    }
};


// 暴力，时间O(n^2)，超时
class Solution_560 {
public:
    int subarraySum(vector<int> &nums, int k) {
        int cnt = 0;

        // [j..i]的总和为k
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j >= 0; --j) {
                sum += nums[j];

                if (sum == k) {
                    cnt++;
                    // 这里不能break，eg：[1,-1,0] k=0时，用了break，当i走到最后一个元素时，j==i发现和正好是0，break了，就少了一种情况
                    //  break;
                }
            }
        }
        return cnt;
    }
};