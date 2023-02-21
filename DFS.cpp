#include <bits/stdc++.h>
using namespace std;
vector<int> *adj;

class Graph
{
    int N, M;

public:
    Graph(int N, int M)
    {
        this->N = N;
        this->M = M;
        adj = new vector<int>[N + 1];
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

    vector<int> DFSofGraph()
    {
        vector<int> vis(N + 1, 0);
        vector<int> storeDFS;

        for (int i = 1; i <= N; i++)
        {
            if (!vis[i])
            {
                stack<int> stack;
                stack.push(i);
                while (!stack.empty())
                {
                    int node = stack.top();
                    stack.pop();

                    if (vis[node])
                    {
                        continue;
                    }
                    vis[node] = true;
                    storeDFS.push_back(node);

                    for (auto it : adj[node])
                    {
                        if (!vis[it])
                        {
                            stack.push(it);
                        }
                    }
                }
            }
        }
        return storeDFS;
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
    cout << "Number of nodes and edges:";
    cin >> n >> m;

    cout << "Add edges to adjacency list: " << endl;
    Graph g(n, m);
    g.addEdge();

    vector<int> dfslist = g.DFSofGraph();
    cout << "DFS iteration : ";
    for (int it : dfslist)
    {
        cout << it << ' ';
    }
    cout << endl;

    // g.printAdjList();
    return 0;
}