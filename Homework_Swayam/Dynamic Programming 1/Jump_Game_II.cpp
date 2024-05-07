class Solution
{
public:
    int n;
    // Recursion
    int solve(vector<int> &nums, int i)
    {
        if (i >= n)
        {
            return 0;
        }
        int mini = INT_MAX;
        for (int j = 1; j < n; j++)
        {
            mini = min(mini, 1 + solve(nums, i + j));
        }
        return mini;
    }

    // Top-Down DP
    int solve(vector<int> &nums, int i, vector<int> &dp)
    {
        if (i >= n)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int mini = INT_MAX;
        for (int j = 1; j < n; j++)
        {
            mini = min(mini, 1 + solve(nums, i + j, dp));
        }
        return dp[i] = mini;
    }

    // Bottom - Up DP
    int solve(vector<int> &nums, vector<int> &dp)
    {
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = INT_MAX;
            for (int j = 1; i + j < n && j <= nums[i]; j++)
            {
                if (dp[i + j] != INT_MAX)
                {
                    dp[i] = min(dp[i], 1 + dp[i + j]);
                }
            }
        }
        return dp[0];
    }
    int jump(vector<int> &nums)
    {
        n = nums.size();
        vector<int> dp(n, INT_MAX);
        return solve(nums, dp);
    }
};