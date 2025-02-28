class Solution
{
public:
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int n, m;

    bool valid(int i, int j)
    {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;
        return true;
    }

    void dfs(int si, int sj, vector<vector<int>> &grid)
    {
        grid[si][sj] = 0; // Mark as visited (convert land to sea)
        for (auto [di, dj] : directions)
        {
            int ci = si + di;
            int cj = sj + dj;
            if (valid(ci, cj) && grid[ci][cj] == 1)
            {
                dfs(ci, cj, grid);
            }
        }
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        n = grid.size(), m = grid[0].size();

        // Remove land cells connected to the boundary using DFS
        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 1)
                dfs(i, 0, grid); // Left boundary
            if (grid[i][m - 1] == 1)
                dfs(i, m - 1, grid); // Right boundary
        }
        for (int j = 0; j < m; j++)
        {
            if (grid[0][j] == 1)
                dfs(0, j, grid); // Top boundary
            if (grid[n - 1][j] == 1)
                dfs(n - 1, j, grid); // Bottom boundary
        }

        // Count remaining land cells
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    count++;
                }
            }
        }

        return count;
    }
};
