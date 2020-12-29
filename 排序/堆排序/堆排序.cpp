// 堆排序.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

void maxHeapify(vector<int>& a, int i, int size) { //下筛维护一个最大堆
    int l = 2 * i + 1, r = 2 * i + 2, largestIdx = i;//左孩子，右孩子，最大值索引
    if (l < size && a[l] > a[i])
        largestIdx = l;
    if (r < size && a[r] > a[largestIdx])
        largestIdx = r;
    swap(a[i], a[largestIdx]);//最大值往上调
    if (largestIdx != i) maxHeapify(a, largestIdx, size);//下筛
}

void buildMaxHeap(vector<int>& a) {
    for (int i = a.size() / 2 - 1; i >= 0; i--) {//建立最大堆
        maxHeapify(a, i, a.size());
    }
}

void heapSort(vector<int>& a) {
    buildMaxHeap(a);
    int size = a.size();
    for (int i = size - 1; i >= 0; i--) {//将最大值取出放在数组最后面
        swap(a[0], a[i]);
        maxHeapify(a, 0, --size);//从零开始下筛，堆规模减1
    }
}

int main()
{
    vector<int> a = { 1,4,3,2,5,6 };
    heapSort(a);
    for (int& i : a) cout << i << " ";
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
