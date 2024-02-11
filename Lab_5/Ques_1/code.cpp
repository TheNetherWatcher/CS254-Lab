#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &m, int row, int col, int rows, int cols)
{
    if (row < 0 || col < 0 || row >= rows || col >= cols || m[row][col] == 0)
        return 0;

    m[row][col] = 0;
    int size = 1;
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            size += dfs(m, row + i, col + j, rows, cols);
        }
    }
    return size;
}

int lrs(vector<vector<int>> &m)
{
    int rows = m.size();
    int cols = m[0].size();

    int maxRegionSize = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (m[i][j] == 1)
            {
                int regionSize = dfs(m, i, j, rows, cols);
                maxRegionSize = max(maxRegionSize, regionSize);
            }
        }
    }
    return maxRegionSize;
}

int main()
{
    vector<vector<int>> m = {
        {1, 0, 0, 1, 1, 0},
        {0, 1, 0, 1, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {1, 1, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 1, 0}};

    int largestSize = lrs(m);
    cout << "Size of the largest region: " << largestSize << endl;
    return 0;
}