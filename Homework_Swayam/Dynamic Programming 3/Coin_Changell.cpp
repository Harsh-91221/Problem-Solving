class Solution
{
public:
    int n;
    // Recursion
    int solve(int i, int amount, vector<int> &coins)
    {
        if (i >= n)
        {
            return 0;
        }
        if (amount == 0)
        {
            return 1;
        }
        if (amount < 0)
        {
            return 0;
        }
        int combination = 0;
        combination += solve(i, amount - coins[i], coins);
        combination += solve(i + 1, amount, coins);
        return combination;
    }

    // Top - Down DP
    int solve(int i, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (i >= n)
        {
            return 0;
        }
        if (amount == 0)
        {
            return 1;
        }
        if (amount < 0)
        {
            return 0;
        }
        if (dp[i][amount] != -1)
        {
            return dp[i][amount];
        }
        int combination = 0;
        combination += solve(i, amount - coins[i], coins, dp);
        combination += solve(i + 1, amount, coins, dp);
        return dp[i][amount] = combination;
    }

    // Bottom - Up DP
    int solve(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                dp[j] += dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
    int change(int amount, vector<int> &coins)
    {
        n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return solve(amount, coins);
    }
};