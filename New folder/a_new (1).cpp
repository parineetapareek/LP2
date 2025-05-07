#include <iostream>
#include <cmath>
using namespace std;

const int N = 5;
int grid[N][N] = {                                                            
    {0, 1, 0, 0, 0},                                                   
    {0, 1, 0, 1, 0},                                                                  
    {0, 0, 0, 1, 0},                                            
    {1, 1, 0, 0, 0},
    {0, 0, 0, 1, 0},                                                                
};

struct Node {
    int x, y, cost, total;
};

const int MAX = 100;
Node pq[MAX];  // simple array as priority queue
int pqSize = 0;

void push(Node n) {
    int i = pqSize - 1;
    while (i >= 0 && pq[i].total > n.total) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = n;
    pqSize++;
}

Node pop() {
    return pq[--pqSize];
}

bool isEmpty() {
    return pqSize == 0;
}

int heuristic(int x, int y, int tx, int ty) {
    return abs(x - tx) + abs(y - ty);  // Manhattan distance
}

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == 0;
}

void astar(int sx, int sy, int tx, int ty) {
    bool visited[N][N] = {false};
    push({sx, sy, 0, heuristic(sx, sy, tx, ty)});

    while (!isEmpty()) {
        Node node = pop();
        if (visited[node.x][node.y]) continue;
        visited[node.x][node.y] = true;
        cout << "(" << node.x << "," << node.y << ") ";
        if (node.x == tx && node.y == ty) {
            cout << "\nReached target!\n";
            return;
        }

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nx = node.x + dx[i];
            int ny = node.y + dy[i];
            if (isValid(nx, ny) && !visited[nx][ny]) {
                int newCost = node.cost + 1;
                int total = newCost + heuristic(nx, ny, tx, ty);
                push({nx, ny, newCost, total});
            }
        }
    }

    cout << "No path found\n";
}

int main() {
    astar(0, 0, 4, 4);
    return 0;
}
