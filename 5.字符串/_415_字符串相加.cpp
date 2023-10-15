/*
 * https://leetcode.cn/problems/add-strings/
 * */
#include <string>
#include <algorithm>

using namespace std;

/*
 * num1 = 077（nums1位数少，前面补0）
 * num2 = 456
 * */
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1;   // 从末尾开始相加

        int add = 0;     // 进位
        int psum = 0;    // 每位的和
        string result;

        //
        while (i >= 0 || j >= 0 || add > 0) {
            // 下标i<0，表示nums1的位数少了，要在前面补0
            int x = (i >= 0) ? num1[i] - '0' : 0;
            int y = (j >= 0) ? num2[j] - '0' : 0;

            psum = x + y + add;
            if (psum >= 10) {
                psum = psum - 10;
                add = 1;
            }
            else add = 0;
            i--;
            j--;

            result.push_back(psum + '0');   // 输出要进行翻转
        }
        reverse(result.begin(), result.end());

        return result;
    }
};