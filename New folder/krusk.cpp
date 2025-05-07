#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;

struct Edge {
    int u, v, weight;
};

Edge edges[MAX];
int parent[MAX];
int n, e; // number of vertices and edges

// Find with path compression
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union by root
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    parent[rootX] = rootY;
}

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

void kruskal() {
    // Initialize parents
    for (int i = 0; i < n; i++)
        parent[i] = i;

    sort(edges, edges + e, compare); // Sort edges by weight

    int mst_weight = 0;
    cout << "\nEdges in the Minimum Spanning Tree:\n";

    for (int i = 0; i < e; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (find(u) != find(v)) {
            cout << u << " - " << v << " : " << w << endl;
            mst_weight += w;
            unite(u, v);
        }
    }


    cout << "Total weight of MST: " << mst_weight << endl;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    for (int i = 0; i < e; i++) {
        cout << "Enter edge " << i + 1 << " (u v weight): ";
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    kruskal();

    return 0;
}
