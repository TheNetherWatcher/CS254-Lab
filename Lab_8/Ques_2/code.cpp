#include <bits/stdc++.h>
using namespace std;

int g[18][18][2];
long long dp[1 << 18][18][2];

long long min_cost(int n, int m, int mask, int prev, int col)
{
    if (mask == ((1 << n) - 1)) {
        return 0;
    }
    if (dp[mask][prev][col == 1] != 0) {
        return dp[mask][prev][col == 1];
    }

    long long ans = 1e9;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            if (g[prev][i][j] && !(mask & (1 << i)) && (j != col)) {
                long long z = g[prev][i][j] + min_cost(n,m,mask|(1<<i),i,j);
                ans = min(z, ans);
            }
        }
    }

    return dp[mask][prev][col == 1] = ans;
}

void make_graph(vector<pair<pair<int,int>, pair<int,char>>>& vp,int m){
    for (int i = 0; i < m; i++) {
        int a = vp[i].first.first - 1;
        int b = vp[i].first.second - 1;
        int cost = vp[i].second.first;
        char color = vp[i].second.second;
        g[a][b][color == 'W'] = cost;
        g[b][a][color == 'W'] = cost;
    }
}

// void get_edges(int n, int m, vector<pair<pair<int,int>, pair<int,char>>>& vp){
//     cout << "Edges:\n";
//     for (int i = 0; i < m; i++) {
//         int a = vp[i].first.first;
//         int b = vp[i].first.second;
//         int cost = vp[i].second.first;
//         char color = vp[i].second.second;
//         cout << a << " - " << b << " (Cost: " << cost << ", Color: " << color << ")\n";
//     }
// }

int main()
{
    int n = 3, m = 4;
    vector<pair<pair<int, int>, pair<int, char> > > vp = {
        { { 1, 2 }, { 2, 'B' } },
        { { 1, 2 }, { 3, 'W' } },
        { { 2, 3 }, { 4, 'W' } },
        { { 2, 3 }, { 5, 'B' } }
    };

    make_graph(vp,m);
    // get_edges(n, m, vp);
    cout << "Minimum cost: " << min_cost(n,m,1,0,2) << '\n';
    return 0;
}
