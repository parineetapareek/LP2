#include <iostream>
using namespace std;

int m[10][10], n, visit[10];
int q[100], front = 0, rear = 0;

void bfs(int s) {
    
    if (front == 0 && rear == 0) {
        visit[s] = 1;
        q[rear] = s;
        rear++;
    }

    if (front == rear)
        return;

    int current = q[front];
    front++;
    cout << current << " - ";

    for (int i = 0; i < n; i++) {
        if (m[current][i] == 1 && !visit[i]) {
            visit[i] = 1;
            q[rear] = i;
            rear++;
        }
    }

    bfs(s); 
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

    cout << "BFS Traversal:\n";
    bfs(s);

    return 0;
}
