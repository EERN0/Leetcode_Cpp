/*
 * https://leetcode.cn/problems/two-sum/
 * */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * 进阶：
 * 167.两数之和II-输入有序数组    https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
 * 40.组合总和Ⅱ  https://leetcode.cn/problems/combination-sum-ii/
 * */
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;
        int s;

        for (int i = 0; i < nums.size(); ++i) {
            s = target - nums[i];

            if (map.find(s) != map.end()) {  // 说明s在map中
                return {map[s], i};             // map[s]——返回key为s的value值
            }

            /*
             * unordered_map的插入：
             * 1. map.insert(pair<int,int>(key,value));
             * 2. map.insert(make_pair(key,value));
             * 3. map[key] = value;
             * */
            map.insert(make_pair(nums[i], i));  // 把访问过的元素加入到map中，key-value, nums[i]为key，下标为value
        }
        return {};
    }
};

/*
 * 腾讯面试两数之和变形：
 * 给你一个array=[1,9,134,10,25,40,4,7], 数组内无重复元素，给一个target，返回所有A+B=target的（pair对）
 * 比如是target=11，返回[(1,10),(4,7)],每个元素只能用一次
 * */
class Solution1 {
public:
    vector<pair<int, int>> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> umap;
        vector<pair<int, int>> result;

        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            if (!umap.count(diff)) {
                umap[nums[i]] = i;
            }
            else {
                // diff差值在哈希表中
                result.push_back({diff, nums[i]});
            }
        }
        return result;
    }
};


int main() {
//    vector<int> nums = {2, 7, 11, 15};
//    vector<int> nums = {3, 3};

//    vector<int> nums;
//    // 输入一个数组
//    while (true) {
//        int a;
//        cin >> a;
//        nums.push_back(a);
//        if (cin.get() == '\n') {
//            break;
//        }
//    }
//    int target;
//    cin >> target;

//    Solution solution;
//    vector<int> res = solution.twoSum(nums, target);
//    for (auto o: res) {
//        cout << o << " ";
//    }

    vector<int> nums = {1, 9, 134, 10, 25, 40, 4, 7};
    Solution1 solution1;
    vector<pair<int, int>> res = solution1.twoSum(nums, 11);
    for (auto o: res) {
        cout << o.first << " " << o.second << " ";
    }

    return 0;
}