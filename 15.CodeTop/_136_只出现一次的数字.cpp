// https://leetcode.cn/problems/single-number/
// Created by caokang on 2023/11/16.
// 关联 lc540. 有序数组中的单一元素
#include <iostream>
#include <vector>

using namespace std;

// 题目说了，一个数出现了1次，其它的都出现了2次，所有元素进行【异或】操作，最后留下的就是出现一次的数
// 异或操作的时间O(n), 空间O(1)
// a⊕a⊕b⊕b⊕x = 0 ⊕ 0 ⊕ x = x
class Solution136 {
public:
    int singleNumber(vector<int> &nums) {
        if (nums.size() == 1) return nums[0];

        int x = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            x = x xor nums[i];
        }

        return x;
    }
};

int main() {
    /*
     * 异或操作: 相同为0，相异为1 (针对二进制数0和1)
     * 0.异或满足交换律, a⊕b = b⊕a
     * 1.二进制数值进行异或计算
     * 2.十进制先得转换为二进制，再进行异或运算
     * */
    int x = 10 xor 10;  // 二进制数位全相同，异或为0
    int y = 15 xor 1;   // 14
    int z = 0 ^ 15;     // 15

    cout << "x=" << x << ", y=" << y << endl;
    cout << "z=" << z << endl;
}