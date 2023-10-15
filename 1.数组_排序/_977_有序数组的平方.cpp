// https://leetcode-cn.com/problems/squares-of-a-sorted-array/
#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    vector<int> sortedSquares(vector<int> &A) {
//        int left = 0;
//        int right = A.size() - 1;
//
//        vector<int> B(A.size(), 0);     // 确定容器 B的大小跟 A一样大，并赋初值全为0
//
//        int k = A.size() - 1;
//        // 结束条件：left > right
//        while (k >= 0 && left <= right) {
//            if (A[left] * A[left] >= A[right] * A[right]) { // 大的数放到新数组的后面
//                B[k--] = A[left] * A[left];
//                left++;
//            } else {
//                B[k--] = A[right] * A[right];
//                right--;
//            }
//        }
//        return B;
//    }
//};


class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        int k = n - 1;

        for (int i = 0, j = n - 1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                result[k] = nums[i] * nums[i];
                k--, i++;
            } else {    // nums[i] * nums[i] <= nums[j] * nums[j]
                result[k] = nums[j] * nums[j];
                k--, j--;
            }
        }
        return result;
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
    vector<int> v = {-4, -1, 0, 3, 10};
    Solution s;

    vector<int> v2 = s.sortedSquares(v);
    printVector(v2);
}

int main() {
    test();
    return 0;
}