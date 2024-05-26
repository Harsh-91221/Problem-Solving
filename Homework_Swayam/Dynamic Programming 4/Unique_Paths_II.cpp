class Solution
{
public:
    // Recursion
    int solve(int i, int j, int m, int n, vector<vector<int>> &obstacleGrid)
    {
        if (i >= m || j >= n || obstacleGrid[i][j] == 1)
        {
            return 0;
        }
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }
        int down = solve(i + 1, j, m, n, obstacleGrid);
        int right = solve(i, j + 1, m, n, obstacleGrid);
        return down + right;
    }

    // Top - Down DP
    int solve(int i, int j, int m, int n, vector<vector<int>> &obstacleGrid, vector<vector<int>> &dp)
    {
        if (i >= m || j >= n || obstacleGrid[i][j] == 1)
        {
            return 0;
        }
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int down = solve(i + 1, j, m, n, obstacleGrid, dp);
        int right = solve(i, j + 1, m, n, obstacleGrid, dp);
        return dp[i][j] = down + right;
    }

    //Bottom - Up DP
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (!obstacleGrid[i - 1][j - 1])
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};