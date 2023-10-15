/*
 * 堆排序
 * */
#include <iostream>
#include <vector>

using namespace std;

class HeapSort {
public:
    /*
     * 堆排序: 不稳定, 空间复杂度为O(1), 时间复杂度为O(nlogn)
     * > - 建堆时间复杂度O(n)
     * > - 堆排序O(nlogn)
     * */
    // 建立大根堆
    void buildMaxHeap(vector<int> &A, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i)     // 从后往前调整所有非终端节点
        {
            headAdjust(A, i, heapSize);
        }
    }

    // 将以k为根的子树调整为大根堆（小元素不断下坠）
    void headAdjust(vector<int> &A, int k, int heapSize) {
        A[0] = A[k];    // A[0]暂存子树的根节点
        for (int i = 2 * k; i <= heapSize; i *= 2)   // i=2*k是k的左孩子，
        {
            if (i < heapSize && A[i] < A[i + 1]) i++;    // 取出关键字key较大子节点的下标
            if (A[0] >= A[i]) break;    // i节点的关键字大于左、右子节点关键字的最大值，大根堆调整结束
            else    // i节点的关键字小于子节点的
            {
                A[k] = A[i];  // 将A[i]调整到父节点上
                k = i;  // 修改k的值，继续向下调整
            }
        }
        A[k] = A[0];    // 被筛选节点的值放入最终位置
    }

    // 基于大根堆进行排序
    void maxHeapSort(vector<int> &A, int len) {
        buildMaxHeap(A, len);    // 建立初始大根堆
        for (int i = len; i > 1; i--) {
            swap(A[1], A[i]);   // 堆顶元素（最大）和堆底元素交换
            headAdjust(A, 1, i - 1);    // 把剩余的待排序元素整理成堆
        }
    }
};


int main() {
    vector<int> nums = {-1, 87, 45, 78, 32, 17, 65, 53, 9};
    HeapSort heapSort;
    heapSort.maxHeapSort(nums, nums.size() - 1);

    for (const auto &o: nums) {
        cout << o << " ";
    }
    cout << endl;

    return 0;
}