class Solution
{
public:
    // Recursion
    int solve(int n, int k, int target)
    {
        int ans = 0;
        if (n < 0)
        {
            return 0;
        }
        if (n == 0 && target == 0)
        {
            return 1;
        }
        if (n == 0 && target != 0)
        {
            return 0;
        }
        if (n != 0 && target == 0)
        {
            return 0;
        }
        for (int i = 1; i <= k; i++)
        {
            if (target - i >= 0)
            {
                ans += solve(n - 1, k, target - i);
            }
        }
        return ans;
    }

    // Top-Down DP
    int solve(int n, int k, int target, vector<vector<int>> &dp)
    {
        int ans = 0;
        if (n < 0)
        {
            return 0;
        }
        if (n == 0 && target == 0)
        {
            return 1;
        }
        if (n == 0 && target != 0)
        {
            return 0;
        }
        if (n != 0 && target == 0)
        {
            return 0;
        }
        if (dp[n][target] != -1)
        {
            return dp[n][target];
        }
        for (int i = 1; i <= k; i++)
        {
            if (target - i >= 0)
            {
                ans = ans % mod + (solve(n - 1, k, target - i, dp) % mod) % mod;
            }
        }
        dp[n][target] = ans;
        return dp[n][target] % mod;
    }

    // Bottom - Up DP
    int solve(int n, int k, int target, vector<vector<int>> &dp)
    {
        dp[0][0] = 1;
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < target + 1; j++)
            {
                int ways = 0;
                for (int face = 1; face <= k; face++)
                {
                    if (j >= face)
                    {
                        ways = (ways + dp[i - 1][j - face]) % mod;
                    }
                }
                dp[i][j] = ways;
            }
        }
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        return solve(n, k, target, dp);
    }
};