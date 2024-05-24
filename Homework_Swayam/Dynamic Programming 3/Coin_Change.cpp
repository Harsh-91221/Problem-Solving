class Solution
{
public:
    int n;
    // Recursion
    int solve(vector<int> &coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        if (amount < 0)
        {
            return -1;
        }
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int ans = solve(coins, amount - coins[i]);
            if (ans != -1)
            {
                mini = min(mini, ans + 1);
            }
        }
        if (mini == INT_MAX)
        {
            return -1;
        }
        else
        {
            return mini;
        }
    }

    // Top-Down DP
    int solve(vector<int> &coins, int amount, vector<int> &dp)
    {
        if (amount == 0)
        {
            return 0;
        }
        if (amount < 0)
        {
            return INT_MAX;
        }
        if (dp[amount] != -1)
        {
            return dp[amount];
        }
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int ans = solve(coins, amount - coins[i], dp);
            if (ans != INT_MAX)
            {
                mini = min(mini, ans + 1);
            }
        }
        return dp[amount] = mini;
    }

    // Bottom - Up DP
    int solve(vector<int> &coins, int amount)
    {
        // STEP 1:CREATE DP ARRAY
        vector<int> dp(amount + 1, INT_MAX);
        // STEP 2: BASE CASE
        dp[0] = 0;
        // STEP 3: CHECK RANGE AND FLOW OF TOP DOWN
        for (int i = 1; i <= amount; i++)
        {
            int mini = INT_MAX;
            for (int j = 0; j < coins.size(); j++)
            {
                if (i - coins[j] >= 0)
                {
                    int ans = dp[i - coins[j]];
                    if (ans != INT_MAX)
                    {
                        mini = min(mini, ans + 1);
                    }
                }
            }
            dp[i] = mini;
        }
        return dp[amount];
    }
    int coinChange(vector<int> &coins, int amount)
    {
        n = coins.size();
        vector<int> dp(amount + 1, -1);
        int ans = solve(coins, amount);
        if (ans == INT_MAX)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};