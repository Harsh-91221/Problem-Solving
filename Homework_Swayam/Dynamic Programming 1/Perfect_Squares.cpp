class Solution
{
public:
    // Recursion
    int solve(int n)
    {
        long long mini = INT_MAX;
        if (n == 0)
        {
            return 0;
        }
        for (int i = 1; i * i <= n; i++)
        {
            long long res = 1 + solve(n - i * i);
            mini = min(mini, res);
        }
        return mini;
    }

    // Top-Down DP
    int solve(int n, vector<int> &dp)
    {
        long long mini = INT_MAX;
        if (n == 0)
        {
            return 0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        for (int i = 1; i * i <= n; i++)
        {
            long long res = 1 + solve(n - i * i, dp);
            mini = min(mini, res);
        }
        return dp[n] = mini;
    }

    // Bottom - Up DP
    int solve(int n, vector<int> &dp)
    {
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = i;

            for (int j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }
        return dp[n];
    }
    int numSquares(int n)
    {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};