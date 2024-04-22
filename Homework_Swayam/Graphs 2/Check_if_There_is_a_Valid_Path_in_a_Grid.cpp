class Solution
{
public:
    int n, m;
    bool isValid(int i, int j)
    {
        if (i >= 0 && i < n && j >= 0 && j < m)
        {
            return true;
        }
        return false;
    }
    void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {
        if (vis[i][j])
        {
            return;
        }
        vis[i][j] = true;
        int up = 0, down = 0, left = 0, right = 0;
        if (grid[i][j] == 1)
        {
            left = 1;
            right = 1;
        }
        else if (grid[i][j] == 2)
        {
            up = 1;
            down = 1;
        }
        else if (grid[i][j] == 3)
        {
            left = 1;
            down = 1;
        }
        else if (grid[i][j] == 4)
        {
            down = 1;
            right = 1;
        }
        else if (grid[i][j] == 5)
        {
            left = 1;
            up = 1;
        }
        else
        {
            right = 1;
            up = 1;
        }
        if (up)
        {
            int new_i = i - 1, new_j = j;
            if (isValid(new_i, new_j) && (grid[new_i][new_j] == 2 || grid[new_i][new_j] == 3 || grid[new_i][new_j] == 4))
            {
                dfs(new_i, new_j, grid, vis);
            }
        }
        if (down)
        {
            int new_i = i + 1, new_j = j;
            if (isValid(new_i, new_j) && (grid[new_i][new_j] == 2 || grid[new_i][new_j] == 5 || grid[new_i][new_j] == 6))
            {
                dfs(new_i, new_j, grid, vis);
            }
        }
        if (left)
        {
            int new_i = i, new_j = j - 1;
            if (isValid(new_i, new_j) && (grid[new_i][new_j] == 1 || grid[new_i][new_j] == 4 || grid[new_i][new_j] == 6))
            {
                dfs(new_i, new_j, grid, vis);
            }
        }
        if (right)
        {
            int new_i = i, new_j = j + 1;
            if (isValid(new_i, new_j) && (grid[new_i][new_j] == 1 || grid[new_i][new_j] == 3 || grid[new_i][new_j] == 5))
            {
                dfs(new_i, new_j, grid, vis);
            }
        }
    }
    bool hasValidPath(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        dfs(0, 0, grid, vis);
        return vis[n - 1][m - 1];
    }
};