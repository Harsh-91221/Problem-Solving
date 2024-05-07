class Solution
{
public:
    int climbStairs(int n)
    {
        // Recursion
        if (n == 1 || n == 2)
        {
            return n;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);

        // Top - Down DP
        vector<int> dp(n + 1, -1);
        if (n == 1 || n == 2)
        {
            return n;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);

        // Bottom - Up DP
        if (n == 1 || n == 2)
        {
            return n;
        }
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];

        // Space Optimization
        if (n == 1 || n == 2)
        {
            return n;
        }
        int prev = 1;
        int curr = 1;
        for (int i = 2; i <= n; i++)
        {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
};