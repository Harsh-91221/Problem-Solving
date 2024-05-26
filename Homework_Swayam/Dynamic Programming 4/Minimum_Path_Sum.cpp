class Solution
{
public:
    // Recursion
    int solve(int i, int j, int m, int n, vector<vector<int>> &grid)
    {
        if (i == m - 1 && j == n - 1)
        {
            return grid[i][j];
        }
        if (i >= m || j >= n)
        {
            return INT_MAX;
        }
        int down = solve(i + 1, j, m, n, grid);
        int right = solve(i, j + 1, m, n, grid);
        return grid[i][j] + min(down, right);
    }

    // Top - Down DP
    int solve(int i, int j, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i == m - 1 && j == n - 1)
        {
            return grid[i][j];
        }
        if (i >= m || j >= n)
        {
            return INT_MAX;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int down = solve(i + 1, j, m, n, grid, dp);
        int right = solve(i, j + 1, m, n, grid, dp);
        return dp[i][j] = grid[i][j] + min(down, right);
    }

    // Bottom - Up DP
    int solve(int m, int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            dp[m - 1][i] = dp[m - 1][i + 1] + grid[m - 1][i];
        }
        for (int i = m - 2; i >= 0; i--)
        {
            dp[i][n - 1] = dp[i + 1][n - 1] + grid[i][n - 1];
        }
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = n - 2; j >= 0; j--)
            {
                dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        return solve(0, 0, m, n, grid);
    }
};