class Solution
{
public:
    // Recursion
    int solve(int i, int j, int m, int n)
    {
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }
        if (i >= m || j >= n)
        {
            return 0;
        }
        int down = solve(i + 1, j, m, n);
        int right = solve(i, j + 1, m, n);
        return down + right;
    }

    // Top - Down DP
    int solve(int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }
        if (i >= m || j >= n)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int down = solve(i + 1, j, m, n, dp);
        int right = solve(i, j + 1, m, n, dp);
        return dp[i][j] = down + right;
    }

    // Bottom - Up DP
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};