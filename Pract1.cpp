#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
queue<int> q;

void addEdge(int e1, int e2)
{
    adj[e1].push_back(e2);
    adj[e2].push_back(e1);
}

void dfs(int node)
{
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor);
        }
    }
}

void bfs()
{
    if (q.empty())
        return;

    int node = q.front();
    q.pop();
    cout << node << " ";

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            visited[neighbor] = true;
            q.push(neighbor);
        }
    }

    bfs();
}

int main()
{
    int n, e, start;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    adj.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < e; i++)
    {
        int e1, e2;
        cout << "Enter edge " << i + 1 << " : " << endl;
        cin >> e1 >> e2;
        addEdge(e1, e2);
    }

    cout << "Enter Starting Node: ";
    cin >> start;

    cout << "DFS: " << endl;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    dfs(start);

    cout << "\nBFS: " << endl;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    visited[start] = true;
    q.push(start);
    bfs();

    return 0;
}