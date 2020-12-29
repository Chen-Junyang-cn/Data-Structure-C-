// 快速排序.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& a, int l, int r) { //待划分数组的左右闭区间
    int pivit = a[l], idx = l; //枢轴点值和索引
    for (int j = l + 1; j <= r; j++) {
        if (a[j] <= pivit) {
            idx++;
            swap(a[j], a[idx]);
        }
    }
    swap(a[idx], a[l]);
    return idx;
}

void quickSort(vector<int>& a, int l, int r) {
    if (l < r) {
        int p = partition(a, l, r);
        quickSort(a, l, p - 1);
        quickSort(a, p + 1, r);
    }
}

int main()
{
    vector<int> a = { 5,4,3,2,1,0 };
    quickSort(a, 0, a.size() - 1);
    for (int& num : a) cout << num << " ";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
