/*
 * 字节面试题
 * https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/description/
 * 给你一个字符串s和一个整数k，请你找出s中的最长子串，要求该子串中的每一字符出现次数都不少于k。返回这一子串的长度。
 * */

#include <iostream>
#include <vector>

using namespace std;

// 递归-分治，超时
class Solution {
public:
    int dfs(string s, int left, int right, int k) {
        if (left > right) return 0;

        // 统计26个字母的出现次数
        vector<int> cnt(26, 0);
        for (int i = left; i <= right; ++i) {
            cnt[s[i] - 'a']++;
        }

        char split = ' '; // split是字符串s中少于k个的字符，不出现在结果中，用来分割数组
        for (int i = 0; i < 26; i++) {
            // 把出现少于k次的标记为split，一次只标记1个字符
            if (cnt[i] > 0 && cnt[i] < k) {
                split = i + 'a';
                break;
            }
        }

        // s中每一个字符都至少出现了k次, 最长字串就是s
        if (split == ' ') {
            return right - left + 1;
        }

        int maxLen = 0;
        int leftLength = 0, rightLength = 0;
        for (int i = left; i <= right; ++i) {
            if (s[i] == split) {
                leftLength = dfs(s, left, i - 1, k);        // 分隔符左边最长子串
                rightLength = dfs(s, i + 1, right, k);       // 分隔符右边最长子串
                maxLen = max(leftLength, rightLength);
            }
        }
        return maxLen;
    }

    int longestSubstring(string s, int k) {
        int n = s.size();
        return dfs(s, 0, n - 1, k);
    }
};

int main() {
    string s = "aabbacccddeeee";
    s = "ababbc";

    // 两个递归过不了下面的样例
    s = "zzzzzzzzzzaaaaaaaaabbbbbbbbhbhbhbhbhbhbhicbcbcibcbccccccccccbbbbbbbbaaaaaaaaafffaahhhhhiaahiiiiiiiiifeeeeeeeeee";
    int k = 10;

    Solution solution;
    int maxLength = solution.longestSubstring(s, k);
    cout << "max-length: [" << maxLength << "]" << endl;
    return 0;
}