// 拓扑排序.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> res;//拓扑排序结果
int cnt = 0;//计数器

void dfs(vector<vector<int>> graph, vector<int>& vis, int s) {
    vis[s] = 1;
    for (int& ner : graph[s]) {//遍历当前节点所有邻接点
        if (!vis[ner])
            dfs(graph, vis, ner);
    }
    res[--cnt] = s;
}

void topoSort(vector<vector<int>> graph) {
    vector<int> vis(graph.size(), 0);
    res = vector<int>(graph.size()), cnt = res.size();
    for (int i = 0; i < graph.size(); i++) {
        if (!vis[i])
            dfs(graph, vis, i);
    }
}

int main()
{
    vector<vector<int>> graph = { {1,3},{5},{1,5},{},{0,1,5},{} };
    topoSort(graph);
    for (int& num : res) cout << num << " ";
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
