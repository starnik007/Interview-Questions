// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j)
{
    if (vis[i][j] || !grid[i][j])
        return;
    vis[i][j] = 1;
    if (i - 1 >= 0)
        dfs(grid, vis, i - 1, j);
    if (i + 1 < grid.size())
        dfs(grid, vis, i + 1, j);
    if (j - 1 >= 0)
        dfs(grid, vis, i, j - 1);
    if (j + 1 < grid[0].size())
        dfs(grid, vis, i, j + 1);
}

int countIslands(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size(), count = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (!vis[i][j] && grid[i][j])
            {
                dfs(grid, vis, i, j);
                ++count;
            }
        }
    }
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
        }
    }
    cout << "Number of islands : " << countIslands(grid) << endl;
}