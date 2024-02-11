#include <bits/stdc++.h>
using namespace std;

const int num_ver = 6;

bool biHelper(int graph[][num_ver], int src, int colorArr[])
{
    colorArr[src] = 1;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < num_ver; ++v)
        {
            if (graph[u][v] && colorArr[v] == -1)
            {
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
            else if (graph[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }
    return true;
}

bool biChecker(int graph[][num_ver])
{
    int colorArr[num_ver];
    for (int i = 0; i < num_ver; ++i)
        colorArr[i] = -1;
    for (int i = 0; i < num_ver; i++)
        if (colorArr[i] == -1)
            if (biHelper(graph, i, colorArr) == false)
                return false;
    return true;
}

bool canBeDone(int graph[][num_ver])
{
    int compGraph[num_ver][num_ver];
    for (int i = 0; i < num_ver; i++)
        for (int j = 0; j < num_ver; j++)
            compGraph[i][j] = (i != j) ? !graph[i][j] : 0;
    return biChecker(compGraph);
}

int main()
{
    int graph[num_ver][num_ver] = {
        {0, 1, 1, 1, 0, 0},
        {1, 0, 1, 0, 0, 1},
        {1, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1, 0},
        {0, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0}};
    if (canBeDone(graph))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}