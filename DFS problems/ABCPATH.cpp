// https://www.spoj.com/problems/ABCPATH/

// https://tanjim131.github.io/2020-06-03-SPOJ-ABCPATH/ ----solution

// This is a simple 2d Graph Traversal Problem. We can use multi-source BFS or DFS.

// We check each cell of the 2d
// grid and if it contains 'A' then we launch a DFS from that cell.
// In each DFS call, we check the neighboring 8 cells (as diagonal cells are considered neighboring cells also),
// and if it contains the next lexicographical character, we move on to that cell. In each valid iteration,
// we increment the current path length by 1, and we update the max path length also.

#include <bits/stdc++.h>
using namespace std;
vector<int> *adj;

int maxPathlen = 0;
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1}; // 8 direction

bool isValid(vector<vector<char>> &grid, int row, int col)
{
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size())
        return false;
    return true;
}

void dfs(vector<vector<char>> &grid,
         vector<vector<int>> &vis, int row, int col, int cur_len = 1)
{
    if (vis[row][col])
    {
        return;
    }
    vis[row][col] = 1;
    maxPathlen = max(maxPathlen, cur_len);
    for (int i = 0; i < 8; i++)
    {
        int n_x = row + dx[i];
        int n_y = col + dy[i];

        if (isValid(grid, n_x, n_y))
        {
            if (grid[n_x][n_y] - grid[row][col] == 1)
            {
                dfs(grid, vis, n_x, n_y, cur_len + 1);
            }
        }
    }
}

void dfsFull(vector<vector<char>> &grid,
             vector<vector<int>> &vis)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 'A')
            {
                dfs(grid, vis, i, j);
            }
        }
    }
}

int main()
{
    int row, col, t = 0;
    while (cin >> row >> col)
    {
        if (!row && !col)
        {
            break;
        }
        vector<vector<char>> grid(row, vector<char>(col));
        vector<vector<int>> vis(row, vector<int>(col));

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cin >> grid[i][j];
            }
        }

        dfsFull(grid, vis);
        cout << "Case " << ++t << ": " << maxPathlen << '\n';
        maxPathlen = 0;
    }

    return 0;
}