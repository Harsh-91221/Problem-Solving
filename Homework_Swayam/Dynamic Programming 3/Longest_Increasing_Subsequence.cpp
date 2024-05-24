class Solution
{
public:
    // Recursion
    int solve(int i, vector<int> &nums, int prev)
    {
        if (i >= nums.size())
        {
            return 0;
        }
        int inc = 0;
        if (prev == -1 || nums[i] > nums[prev])
        {
            inc = 1 + solve(i + 1, nums, i);
        }
        int exc = solve(i + 1, nums, prev);
        return max(exc, inc);
    }

    // DP Top - Down
    int solve(int i, vector<int> &nums, int prev, vector<vector<int>> &dp)
    {
        if (i >= nums.size())
        {
            return 0;
        }
        if (dp[i][prev + 1] != -1)
        {
            return dp[i][prev + 1];
        }
        int inc = 0;
        if (prev == -1 || nums[i] > nums[prev])
        {
            inc = 1 + solve(i + 1, nums, i, dp);
        }
        int exc = solve(i + 1, nums, prev, dp);
        return dp[i][prev + 1] = max(exc, inc);
    }

    // DP Bottom - UP
    int solveTab(vector<int> &nums, int index, int prev)
    {
        if (index >= nums.size())
        {
            return 0;
        }
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (index = n - 1; index >= 0; index--)
        {
            for (prev = index - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || nums[index] > nums[prev])
                {
                    include = 1 + dp[index + 1][index + 1];
                }
                int exclude = dp[index + 1][prev + 1];
                dp[index][prev + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int> &nums)
    {
        return solve(0, nums, -1);
    }
};
