#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int N, M;
    vector<int> *adj;

public:
    Graph(int N, int M)
    {
        this->N = N;
        this->M = M;
        adj = new vector<int>[N];
    }

    void addEdge()
    {

        for (int i = 0; i < M; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }
    void printAdjList()
    {
        for (int i = 0; i < N; i++)
        {
            cout << "Vertex " << i << "->";
            for (int nbr : adj[i])
            {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n, m;
    cout << "Number of node and edges:";
    cin >> n >> m;

    cout << "Add edges to adjacency list: " << endl;
    Graph g(n, m);
    g.addEdge();
    g.printAdjList();
    return 0;
}