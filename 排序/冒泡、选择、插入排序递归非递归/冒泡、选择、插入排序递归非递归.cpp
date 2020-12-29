// 冒泡、选择、插入排序递归非递归.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int>& a) {
	for (int i = a.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
		}
	}
}

void bubbleRecursionSort(vector<int>& a, int tail) {//tail表示待排数组最后一个元素指针
	if (tail == 0) return;//递归基
	for (int j = 0; j < tail; j++) { //每次处理最后一个元素
		if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
	}
	bubbleRecursionSort(a, --tail);
}

void insertionSort(vector<int>& a) {
	for (int i = 1; i < a.size(); i++) {
		int tmp = a[i], pos = i - 1;
		while (pos >= 0 && a[pos] > tmp) {
			a[pos + 1] = a[pos];
			--pos;
		}
		a[pos + 1] = tmp;
	}
}

void insertionRecursionSort(vector<int>& a, int idx = 1) {//每次处理下标 idx 的元素
	if (idx == a.size()) return;
	int tmp = a[idx], pos = idx - 1;
	while (pos >= 0 && a[pos] > tmp) {//找到 a[idx] 应该放的位置
		a[pos + 1] = a[pos];
		pos--;
	}
	a[pos + 1] = tmp;
	insertionRecursionSort(a, idx + 1);
}

void selectionSort(vector<int>& a) {
	for (int i = 0; i < a.size(); i++) {
		int tmp = a[i], pos = i;
		for (int j = i + 1; j < a.size(); j++) {
			if (a[j] < tmp) {
				tmp = a[i];
				pos = j;
			}
		}
		swap(a[pos], a[i]);
	}
}

void selectionRecursionSort(vector<int>& a, int idx = 0) {//每次处理第idx个元素
	if (idx == a.size()) return;
	int tmp = a[idx], pos = idx;
	for (int j = idx + 1; j < a.size(); j++) {//选择一个最小值
		if (a[j] < tmp) {
			tmp = a[j];
			pos = j;
		}
	}
	swap(a[idx], a[pos]);
	selectionRecursionSort(a, idx + 1);
}

int main()
{
	vector<int> a = { 3,2,1 };
	selectionRecursionSort(a);
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
