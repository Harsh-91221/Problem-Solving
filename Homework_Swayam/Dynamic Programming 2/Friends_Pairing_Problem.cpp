class Solution
{
public:
    // Recursion
    int solve(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        return solve(n - 1) + (n - 1) * solve(n - 2);
    }

    // Top-Down DP
    const int mod = 1e9 + 7;
    int solve(int n, vector<long long int> &dp)
    {
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = solve(n - 1, dp) + (n - 1) * solve(n - 2, dp) % mod;
    }

    // Bottom - Up DP
    const int mod = 1e9 + 7;
    long long int solve(int n, vector<long long int> &dp)
    {
        for (int i = 0; i <= n; i++)
        {
            if (i <= 2)
            {
                dp[i] = i;
            }
            else
            {
                dp[i] = (dp[i - 1] + (i - 1) * dp[i - 2]) % mod;
            }
        }
        return dp[n];
    }

    int countFriendsPairings(int n)
    {
        vector<long long int> dp(n + 1, -1);
        return solve(n, dp);
    }
};