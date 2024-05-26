class Solution
{
public:
    // Recursion
    int solve(int i, vector<int> &nums, int target)
    {
        if (target < 0)
        {
            return -nums.size();
        }
        if (target == 0)
        {
            return 0;
        }
        if (i >= nums.size())
        {
            return -nums.size();
        }
        int take = 1 + solve(i + 1, nums, target - nums[i]);
        int not_take = solve(i + 1, nums, target);
        return max(take, not_take);
    }

    // Top - Down DP
    int solve(int i, vector<int> &nums, int target, vector<vector<int>> &dp)
    {
        if (target < 0)
        {
            return -nums.size();
        }
        if (target == 0)
        {
            return 0;
        }
        if (i >= nums.size())
        {
            return -nums.size();
        }
        if (dp[i][target] != -1)
        {
            return dp[i][target];
        }
        int take = 1 + solve(i + 1, nums, target - nums[i], dp);
        int not_take = solve(i + 1, nums, target, dp);
        return dp[i][target] = max(take, not_take);
    }

    // Bottom - Up DP
    int lengthOfLongestSubsequence(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < target + 1; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1] && dp[i - 1][j - nums[i - 1]] != -1)
                {
                    dp[i][j] = max(1 + dp[i - 1][j - nums[i - 1]], dp[i][j]);
                }
            }
        }
        return dp[n][target];
    }
};