#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    vector<pair<int, int>> edges = {{2, 2}, {1, 3}, {2, 4}, {3, 5}, {1, 5}, {3, 1}};
    
    int time = 0;
    vector<vector<int>> graph(n+1);
    vector<int> low(n+1, -1), disc(n+1, -1);
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        graph[u].push_back(v);
    }
    set<int> articulation_points;
    set<pair<int, int>> bridges;
    
    function<void(int, int)> DFS = [&](int u, int parent) {
        low[u] = disc[u] = time++;
        int children = 0;
        
        for (int v : graph[u]) {
            if (v == parent) continue; 
            
            if (disc[v] == -1) {
                children++;
                DFS(v, u);
                low[u] = min(low[u], low[v]);
                
                if (low[v] > disc[u]) { // Bridge condition
                    bridges.insert({min(u, v), max(u, v)});
                }
                
                if (low[v] >= disc[u] && parent != -1) { 
                    articulation_points.insert(u);
                }
            } else {
                low[u] = min(low[u], disc[v]);
            }
        }
        
        if (parent == -1 && children > 1) { 
            articulation_points.insert(u);
        }
    };
    
    for (int i = 1; i <= n; ++i) {
        if (disc[i] == -1) {
            DFS(i, -1); 
        }
    }
    
    cout << "Articulation Points:\n";
    for (int point : articulation_points) {
        cout << point << endl;
    }
    
    cout << "Bridges:\n";
    for (auto bridge : bridges) {
        cout << bridge.first << " " << bridge.second << endl;
    }
}