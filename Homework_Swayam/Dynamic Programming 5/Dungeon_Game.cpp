class Solution
{
public:
    int m, n;
    // Recursion
    int solve(int i, int j, vector<vector<int>> &dungeon)
    {
        if (i >= m || j >= n)
        {
            return INT_MAX;
        }
        if (i == m - 1 && j == n - 1)
        {
            return (dungeon[i][j] <= 0) ? -dungeon[i][j] + 1 : 1;
        }
        int down = solve(i + 1, j, dungeon);
        int right = solve(i, j + 1, dungeon);
        int ans = min(down, right) - dungeon[i][j];
        return (ans <= 0) ? 1 : ans;
    }

    // Top - Down DP
    int solve(int i, int j, vector<vector<int>> &dungeon, vector<vector<int>> &dp)
    {
        if (i >= m || j >= n)
        {
            return INT_MAX;
        }
        if (i == m - 1 && j == n - 1)
        {
            return (dungeon[i][j] <= 0) ? -dungeon[i][j] + 1 : 1;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int down = solve(i + 1, j, dungeon, dp);
        int right = solve(i, j + 1, dungeon, dp);
        int ans = min(down, right) - dungeon[i][j];
        return dp[i][j] = (ans <= 0) ? 1 : ans;
    }

    // Bottom - Up DP
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        m = dungeon.size();
        n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 && j == n - 1)
                {
                    dp[i][j] = min(0, dungeon[i][j]);
                }
                else if (i == m - 1)
                {
                    dp[i][j] = min(0, dungeon[i][j] + dp[i][j + 1]);
                }
                else if (j == n - 1)
                {
                    dp[i][j] = min(0, dungeon[i][j] + dp[i + 1][j]);
                }
                else
                {
                    dp[i][j] = min(0, dungeon[i][j] + max(dp[i + 1][j], dp[i][j + 1]));
                }
            }
        }
        return abs(dp[0][0]) + 1;
    }
};