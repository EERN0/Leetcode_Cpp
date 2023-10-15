// https://leetcode-cn.com/problems/sub-sort-lcci/
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> subSort(vector<int> &array) {
        if (array.empty() == 1) return vector<int>{-1, -1};     // 数组为空，返回[-1, -1]

        int rpos = -1;           // 最右边的位置，有序返回{-1，-1}
        // 从左往右，应该是逐渐增大的。找逆序对，确定最右边的数
        int max = array[0];     // 扫描过的最大值
        for (int i = 1; i < array.size(); i++) {
            if (max <= array[i]) {
                max = array[i];     // 更新最大值
            } else { // array[i] 小于 max，说明是逆序对，记录右边位置rpos。若不执行else，说明已经有序了，没有逆序对
                rpos = i;
            }
        }
        if (rpos == -1) return vector<int>{-1, -1};     // rpos等于-1，说明没有逆序对

        int lpos = -1;           // 最左边的位置
        // 从右往左，应该是逐渐减小的。找逆序对，确定最左边的数
        int min = array[array.size() - 1];
        for (int i = array.size() - 2; i >= 0; i--) {
            if (min >= array[i]) {
                min = array[i];     // 更新最小值
            } else {     // array[i] 大于 min，说明是逆序对，记录左边位置lpos
                lpos = i;
            }
        }
        return vector<int>{lpos, rpos};
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
//    vector<int> v = {1, 5, 4, 3, 2, 7};
    vector<int> v = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19};
    Solution s;
    vector<int> v2 = s.subSort(v);
    printVector(v2);
}

int main() {
    test();
    return 0;
}
