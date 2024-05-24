// Recursion
int solve(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int ans = 0;
    for (int i = 1; i <= 6 && n - i >= 0; i++)
    {
        ans = (ans + solve(n - i)) % mod;
    }
    return ans;
}
// DP Top - Down
int solve(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = 0;
    for (int i = 1; i <= 6 && n - i >= 0; i++)
    {
        ans = (ans + solve(n - i, dp)) % mod;
    }
    return dp[n] = ans;
}

// DP Bottom - Up
int solve(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; i - j >= 0 && j <= 6; j++)
        {
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }
    return dp[n]
}