// https://leetcode.cn/problems/3sum-closest/
// 只用输出三数之和的结果，结果唯一，不用收集是哪三个数，不需要去重
// 如果考虑要收集结果呢？怎么去重？ 下面代码给出了
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 16. 最接近的三数之和
// 不止求取最接近的和，还要求出这个集合
class Solution16 {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];  // 结果
        vector<int> res;

        int aIndex = 0, bIndex = 1, cIndex = 2;
        // a+b+c ~ target
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // 对a去重
            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];         // 当前三数之和
                if (abs(sum - target) < abs(ans - target)) {    // sum更接近target，更新结果
                    ans = sum;
                    aIndex = i, bIndex = left, cIndex = right;
                }

                if (sum > target) {  // 三数之和大于target，right减小
                    right--;
                }
                else if (sum < target) {    // 三数之和小于target，left增大
                    left++;
                }
                else {  // sum == target，收集一个结果
                    res = {nums[aIndex], nums[bIndex], nums[cIndex]};
                    return sum;
                }
            }
        }
        // 收集一个最接近的结果子集
        res = {nums[aIndex], nums[bIndex], nums[cIndex]};
        return ans;
    }
};

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        // 必须先排序
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; ++i) {
            // 每一轮循环，left和right都要重新开始
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];   // 三数之和

                // 如果sum更接近target，更新结果ans
                if (abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                }
                // sum大于target，减小right
                if (sum > target) {
                    right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {  // sum==target时，三数之和肯定就是最接近target的
                    return sum;
                }
            }
        }
        // for循环中没有发生return，说明没有sum==target的情况，三数之和最接近target的还是ans
        return ans;
    }
};


int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution16 solution16;
    int closest = solution16.threeSumClosest(nums, 0);
    cout << closest << endl;

    return 0;
}