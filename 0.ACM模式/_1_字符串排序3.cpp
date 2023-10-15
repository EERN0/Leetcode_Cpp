// Created by caokang on 2023/5/12.
// https://www.nowcoder.com/exam/test/69329981/detail?pid=27976983#question
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string str;
    vector<string> v;

    while (cin >> str) {
        if (cin.get() != ',') {
            v.push_back(str);
        }

        if (cin.get() == '\n') {    // 遇到换行符，打印输出
            sort(v.begin(), v.end());

            for (int i = 0; i < v.size(); ++i) {
                if (i == v.size() - 1) {
                    cout << v[i] << endl;
                } else {
                    cout << v[i] << ",";
                }
            }
            v.clear();
        }
    }
}