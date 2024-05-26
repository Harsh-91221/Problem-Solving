class Solution
{
public:
    int m;
    int n;
    // Recursion
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    {
        if (i == m - 1)
        {
            return grid[i][j];
        }
        int mini = INT_MAX;
        for (int k = 0; k < n; k++)
        {
            mini = min(mini, grid[i][j] + moveCost[grid[i][j]][k] + solve(i + 1, k, grid, moveCost));
        }
        return mini;
    }

    // Top - Down DP
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &moveCost, vector<vector<int>> &dp)
    {
        if (i == m - 1)
        {
            return grid[i][j];
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int mini = INT_MAX;
        for (int k = 0; k < n; k++)
        {
            mini = min(mini, grid[i][j] + moveCost[grid[i][j]][k] + solve(i + 1, k, grid, moveCost, dp));
        }
        return dp[i][j] = mini;
    }

    // Bottom - Up DP
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    {
        int mini = INT_MAX;
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[m - 1][i] = grid[m - 1][i];
        }
        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = INT_MAX;
                for (int k = 0; k < n; k++)
                {
                    temp = min(temp, dp[i + 1][k] + moveCost[grid[i][j]][k]);
                }
                dp[i][j] = grid[i][j] + temp;
            }
        }
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, dp[0][i]);
        }
        return mini;
    }
};