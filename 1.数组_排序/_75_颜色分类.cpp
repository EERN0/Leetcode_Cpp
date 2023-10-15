// https://leetcode-cn.com/problems/sort-colors/
#include <iostream>
#include <vector>

using namespace std;

/*
 * cur扫描到当前的元素：
 * 0：cur、left都走一个
 * 1：cur走一个
 * 2：right走一个
 * */
class Solution75 {
public:
    void sortColors(vector<int> &nums) {
        int left = 0;                   // 放0的位置
        int right = nums.size() - 1;    // 放1的位置
        int cur = 0;
        // 循环结束条件：cur > right
        while (cur <= right) {
            if (nums[cur] == 1) cur++;
            else if (nums[cur] == 0) { // 将cur和left的值进行交换
                swap(nums[cur], nums[left]);
                cur++;
                left++;
            }
            else { // cur扫描到2，cur指针不动
                swap(nums[cur], nums[right]);
                right--;
            }
        }
    }
};

// 打印 vector
void printVector(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void test() {
    vector<int> v1;
    v1.push_back(2);
    v1.push_back(0);
    v1.push_back(2);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(0);

    Solution75 s;
    s.sortColors(v1);
    printVector(v1);
}

int main() {
    test();
    return 0;
}


