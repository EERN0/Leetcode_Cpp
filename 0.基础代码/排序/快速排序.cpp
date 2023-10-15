/*
 * 1. 快速排序的思想：
 *    在待排序表中任选一个元素pivot作为基准（通常取首元素），通过一趟排序将待排序表划分为左右两个子表，其中左子表元素都小于基准元素，
 *    右子表元素都大于基准元素，则基准元素pivot放在最终位置上，这个过程称为一次“划分”。然后分别递归对两个子表重复上述划分过程，
 *    直至每个部分内只有一个元素或空位置，即所有元素都放到了最终位置
 * 2. 最好时间复杂度：O(nlogn)
 *    平均时间复杂度：O(nlogn)
 *    最坏时间复杂度：O(n^2), 有序表排序时
 * 3. 快排不稳
 * */
#include <iostream>
#include <vector>

using namespace std;

class Sort {
public:
    /*
    * 一个函数搞定快速排序
    * */
    void quickSort(vector<int> &A, int low, int high) {
        if (low >= high) return;    // 递归结束条件
        int left = low, right = high;
        // 随机取一个数作为基准
        srand(time(nullptr));   // 随机数种子
        int random = rand() % (high - low + 1) + low;
        int pivot = A[random];
        swap(A[low], A[random]);     // 把基准元素放到第一个位置上

        while (low < high)  // ① low < high时循环, 未处理low==high的情况
        {
            while (low < high && A[high] >= pivot) high--;
            A[low] = A[high];       // 此时A[high] < pivot，把小的元素放到左边
            while (low < high && A[low] <= pivot) low++;
            A[high] = A[low];
        }
        A[low] = pivot;     // ② 处理low==high的情况，基准放到最终位置
        quickSort(A, left, low - 1);
        quickSort(A, low + 1, right);
    }


    /*
     * 两个函数的快排
     * */
    // 一趟划分，区间[low, high]
    int Partition(vector<int> &A, int low, int high) {
        int pivot = A[low]; // 将区间第一个元素作为基准
        while (low < high)  // low<high时循环, 未处理low==high的情况
        {
            while (low < high && A[high] >= pivot) high--;
            A[low] = A[high]; // 此时A[high] < pivot，把小的元素放到左边
            while (low < high && A[low] <= pivot) low++;
            A[high] = A[low];
        }
        A[low] = pivot;     // 处理low==high的情况，基准放到最终位置
        return low;         // 返回low，将区间划分为左右两个子区间
    }

    // 快速排序
    void QuickSort(vector<int> &nums, int low, int high) {
        if (low < high) {
            int pivotpos = Partition(nums, low, high);  // 一趟划分，分成右两个子表，pivotpos是基准
            // 进行递归
            QuickSort(nums, low, pivotpos - 1);
            QuickSort(nums, pivotpos + 1, high);
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

int main() {
//    vector<int> nums = {49, 38, 65, 97, 76, 13, 27, 49};
//    vector<int> nums = {1, 2};
    vector<int> nums = {5, 4, 4, 3, 3, 2, 1};
    Sort s;
    s.QuickSort(nums, 0, nums.size() - 1);
    printVector(nums);
    s.quickSort(nums, 0, nums.size() - 1);
    printVector(nums);
}