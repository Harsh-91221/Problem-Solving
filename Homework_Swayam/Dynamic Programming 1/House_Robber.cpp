class Solution
{
public:
    // Recursion
    int solve(vector<int> &nums, int i)
    {
        if (i >= nums.size())
        {
            return 0;
        }
        int pick = nums[i] + solve(nums, i + 2);
        int not_pick = solve(nums, i + 1);
        return max(pick, not_pick);
    }

    // Top - Down DP
    int solve(vector<int> &nums, int i, vector<int> &dp)
    {
        if (i >= nums.size())
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int pick = nums[i] + solve(nums, i + 2, dp);
        int not_pick = solve(nums, i + 1, dp);
        return dp[i] = max(pick, not_pick);
    }

    // Bottom - Up DP
    int solve(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int prev1 = 0;
        int prev2 = 0;
        for (auto a : nums)
        {
            int temp = prev1;
            prev1 = max(prev1, prev2 + a);
            prev2 = temp;
        }
        return prev1;
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return solve(nums, 0, dp);
    }
};