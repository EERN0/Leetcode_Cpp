/*
 * 滑动窗口（同向双指针）
 * https://leetcode.cn/problems/longest-substring-without-repeating-characters/
 * */
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        int maxLen = 0;
        unordered_set<char> uset;
        while (j < s.size()) {
            // s[j]不在滑动窗口uset中，加入
            while (j < s.size() && !uset.count(s[j])) {
                uset.insert(s[j]);
                j++;
            }
            // 退出while，说明s[j]已经在滑动窗口中存在过了
            // 删掉s[i]，直到s[j]在滑动窗口中唯一存在，多次while肯定能删掉
            uset.erase(s[i]);
            i++;

            // 计算滑动窗口的长度
            // 若最开始的s[i]和s[j]相同，删掉s[i]再算长度没问题
            int len = j - i + 1;
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};

class Solution2 {
public:
    // s = "abcabcbb"
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();

        unordered_set<char> mySet;  // 存放不重复的子串
        int right = 0;
        int maxSub = 0;

        for (int i = 0; i < s.size(); ++i) {
            while (right < s.size() && !mySet.count(s[right])) {
                mySet.insert(s[right]);
                right++;
            }
            int len = mySet.size();
            maxSub = max(maxSub, len);

            // 退出while，mySet里面是无重复的子串，长度是right-i
            // 下一轮循环，i++，mySet的滑动窗口[i, right-1]要缩小
            mySet.erase(s[i]);
        }
        return maxSub;
    }
};

int main() {
    string s = "abcabcbb";
    Solution2 solution;
    int maxLength = solution.lengthOfLongestSubstring(s);
    cout << "max-length: [" << maxLength << "]" << endl;

    return 0;
}