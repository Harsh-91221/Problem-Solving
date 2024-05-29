// Recursion
int solve(int n)
{
    if (n == 1)
    {
        return 0;
    }
    int a = INT_MAX;
    int b = INT_MAX;
    int c = INT_MAX;
    if (n % 2 == 0)
    {
        a = solve(n / 2);
    }
    if (n % 3 == 0)
    {
        b = solve(n / 3);
    }
    c = solve(n - 1);
    return 1 + min({a, b, c});
}

// DP
int solve(int n, vector<int> &dp)
{
    if (n == 1)
    {
        return 0;
    }
    dp[2] = 1;
    dp[3] = 1;
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int a = INT_MAX;
    int b = INT_MAX;
    int c = INT_MAX;
    if (n % 2 == 0)
    {
        a = solve(n / 2, dp);
    }
    if (n % 3 == 0)
    {
        b = solve(n / 3, dp);
    }
    c = solve(n - 1, dp);
    return dp[n] = 1 + min({a, b, c});
}
