#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a disjoint set (for union-find)
struct DisjointSet {
    int *parent;
    int *rank;  // For optimization

    DisjointSet(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;  // Initially each vertex is its own parent
            rank[i] = 0;    // Initial ranks are 0
        }
    }

    // Find the representative of the set containing vertex 'u'
    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]); // Path compression
        }
        return parent[u];
    }

    // Merge the sets containing vertex 'u' and vertex 'v'
    void merge(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        // Attach smaller rank tree under root of higher rank tree
        if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else {
            parent[root_v] = root_u;
            if (rank[root_u] == rank[root_v]) {
                rank[root_u]++;
            }
        }
    }
};

// Comparator for sorting edges in descending order of weight
bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight > b.weight;
}

// Function to find the maximum spanning tree
vector<Edge> findMaximumSpanningTree(vector<Edge> edges, int n) {
    vector<Edge> mst;

    // Sort edges in descending order of weight
    sort(edges.begin(), edges.end(), compareEdges);

    DisjointSet ds(n);

    for (auto edge : edges) {
        int u = edge.src;
        int v = edge.dest;

        if (ds.find(u) != ds.find(v)) {  // If vertices are not in the same set
            mst.push_back(edge);         // Add edge to the MST
            ds.merge(u, v);              // Merge the sets
        }
    }

    return mst;
}

int main() {
    // int n, m;  // n: number of vertices, m: number of edges
    // cin >> n >> m;

    // vector<Edge> edges(m);
    // for (int i = 0; i < m; i++) {
    //     cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    // }
    // Test input
    int n = 4;  // Number of vertices
    int m = 5;  // Number of edges

    vector<Edge> edges = {
        {0, 1, 2},  // Edge from vertex 0 to vertex 1 with weight 2
        {1, 2, 3},  // Edge from vertex 1 to vertex 2 with weight 3
        {2, 3, 1},  // Edge from vertex 2 to vertex 3 with weight 1
        {0, 3, 4},  // Edge from vertex 0 to vertex 3 with weight 4
        {1, 3, 5}   // Edge from vertex 1 to vertex 3 with weight 5
    };

    // Call the function to find the maximum spanning tree
    vector<Edge> mst = findMaximumSpanningTree(edges, n);

    cout << "Edges in the maximum spanning tree:\n";
    for (auto edge : mst) {
        cout << edge.src << " -- " << edge.dest << " (weight: " << edge.weight << ")\n";
    }

    return 0;
}