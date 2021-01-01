// 最小生成树.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
constexpr auto INF = 0x3f3f3f3f;//声明一个常量INF

void Prim(vector<vector<int>> cost, int beg) {
    int n = cost.size();
    vector<int> vis(n, 0);
    vector<int> lowCost(n, INF);
    lowCost[beg] = 0;//从起始点beg开始添加
    for (int i = 0; i < n; i++) {
        int vtx = -1, Min = INF;
        for (int j = 0; j < n; j++) {//找到代价最小的顶点
            if (!vis[j] && lowCost[j] < Min)
                vtx = j, Min = lowCost[j];
        }
        if (vtx == -1) break;//非连通图
        vis[vtx] = 1;//该点已经被访问(添加入结果集合)
        for (int ner = 0; ner < n; ner++) { //对vtx的所有邻居更新最小代价
            if (!vis[ner] && cost[vtx][ner] < lowCost[ner])
                lowCost[ner] = cost[vtx][ner];
        }
    }
}

int main()
{
    std::cout << "Hello World!\n";
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
