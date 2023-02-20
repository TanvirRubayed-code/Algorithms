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

    vector<int> BFS()
    {
        vector<int> vis(N + 1, 0);
        vector<int> bfs;

        for (int i = 1; i <= N; i++)
        {
            if (!vis[i])
            {
                queue<int> q;
                q.push(i);
                vis[i] = 1;

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    // cout << node << ' ';
                    bfs.push_back(node);

                    for (int it : adj[node])
                    {
                        if (!vis[it])
                        {
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }
        return bfs;
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
    vector<int> bfslist = g.BFS();
    cout << "BFS iteration : ";
    for (int it : bfslist)
    {
        cout << it << ' ';
    }
    cout << endl;
    // g.printAdjList();
    return 0;
}