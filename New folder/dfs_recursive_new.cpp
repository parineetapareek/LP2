#include <iostream>
using namespace std;

int m[10][10], n, visit[10];

void dfs(int s) {
    cout << s << " - " ;
    visit[s] = 1;

    for (int i = 0; i < n; i++) {
        if (m[s][i] == 1 && !visit[i]) {
            dfs(i);  // Recursive call
        }
    }
}

int main() {
    int s;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        visit[i] = 0;
    }

    cout << "Enter the starting node: ";
    cin >> s;

    cout << "DFS Traversal:\n";
    dfs(s);

    return 0;
}
