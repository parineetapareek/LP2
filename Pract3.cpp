#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define V 5

class SelectionSort
{
public:
    void sortArray(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (arr[i] > arr[j])
                {
                    swap(arr[i], arr[j]);
                }
            }
        }

        cout << "Sorted Array: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class PrimMST
{
private:
    int graph[V][V]; // Adjacency matrix to store graph

    // Function to find the vertex with the minimum key value
    int minKey(int key[], bool mstSet[])
    {
        int min = INT_MAX, min_index;
        for (int v = 0; v < V; v++)
        {
            if (!mstSet[v] && key[v] < min)
            {
                min = key[v], min_index = v;
            }
        }
        return min_index;
    }

    // Function to print the constructed MST
    void printMST(int parent[])
    {
        cout << "Edge \tWeight\n";
        for (int i = 1; i < V; i++)
        {
            cout << parent[i] << " - " << i << " \t" << graph[parent[i]][i] << "\n";
        }
    }

public:
    // Constructor to initialize the graph
    PrimMST(int g[V][V])
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                graph[i][j] = g[i][j];
            }
        }
    }

    // Function to implement Prim's Algorithm to find the MST
    void primMST()
    {
        int parent[V];
        int key[V];
        bool mstSet[V];

        // Initialize all keys as infinite and mstSet[] as false
        for (int i = 0; i < V; i++)
        {
            key[i] = INT_MAX;
            mstSet[i] = false;
        }

        key[0] = 0;     // Starting with the first vertex
        parent[0] = -1; // First node has no parent

        for (int count = 0; count < V - 1; count++)
        {
            int u = minKey(key, mstSet); // Pick the minimum key vertex
            mstSet[u] = true;            // Add the picked vertex to the MST

            // Update key values of the adjacent vertices of the picked vertex
            for (int v = 0; v < V; v++)
            {
                if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        // Print the MST
        printMST(parent);
    }
};

int main()
{
    int arr[] = {80, 23, 97, 10};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    int n = 5;
    int graph[n][n] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};

    SelectionSort ss;
    PrimMST mst(graph);

    ss.sortArray(arr, arrSize);
    mst.primMST();
    return 0;
}