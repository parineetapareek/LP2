#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 5;

int grid[N][N] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {1, 1, 0, 0, 0},
    {0, 0, 0, 1, 0}};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct node
{
    int x, y, g, f, h;
    node *parent;

    node(int x, int y, int g, int h, node *p = nullptr) : x(x), y(y), g(g), h(h), f(g + h), parent(p) {}
};

int getHeuristic(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

bool isValid(int x, int y, bool visited[N][N])
{
    return x >= 0 && x < N && y >= 0 && y < N && grid[x][y] == 0 && !visited[x][y];
}

void printPath(node *end)
{
    vector<node *> path;
    int finalCost = end->g;

    while (end)
    {
        path.push_back(end);
        end = end->parent;
    }

    reverse(path.begin(), path.end());
    cout << "Path: " << endl;
    for (auto n : path)
    {
        cout << "(" << n->x << ", " << n->y << ") ";
    }
    cout << endl;
    cout << "Final Cost: " << finalCost << endl;
}

void aStar(int sx, int sy, int gx, int gy)
{
    vector<node *> openList; // List of nodes to explore
    bool visited[N][N] = {false};

    node *startNode = new node(sx, sy, 0, getHeuristic(sx, sy, gx, gy));
    openList.push_back(startNode);

    while (!openList.empty())
    {
        auto currentIt = min_element(openList.begin(), openList.end(), [](node *a, node *b)
                                     { return a->f < b->f; });

        node *current = *currentIt;
        openList.erase(currentIt);

        int x = current->x;
        int y = current->y;

        if (visited[x][y])
            continue;
        visited[x][y] = true;

        if (x == gx && y == gy)
        {
            printPath(current);
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isValid(nx, ny, visited))
            {
                int g = current->g + 1;
                int h = getHeuristic(nx, ny, gx, gy);
                node *neighbor = new node(nx, ny, g, h, current);
                openList.push_back(neighbor);
            }
        }
    }
    cout << "No Path Found" << endl;
}

int main()
{
    aStar(0, 0, 4, 4);
    return 0;
}