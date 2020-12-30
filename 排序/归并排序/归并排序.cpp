// 归并排序.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& a, int l, int mid, int r) {
    vector<int> tmp(a.size(), 0);
    int i = l, j = mid + 1, k = l;//左边数组的索引，右边数组的索引，结果数组的索引
    while (i <= mid && j <= r) {
        if (a[i] < a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (int idx = l; idx <= r; idx++)
        a[idx] = tmp[idx];
}

void mergeSort(vector<int>& a, int l, int r) {//排序区间[l,r]
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}

int main()
{
    vector<int> a = { 5,4,3,2,1 };
    mergeSort(a, 0, a.size() - 1);
    for (int& num : a) cout << num;
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
