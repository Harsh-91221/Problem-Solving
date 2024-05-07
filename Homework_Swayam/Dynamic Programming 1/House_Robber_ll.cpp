class Solution
{
public:
    // Recursion
    int solve(vector<int> &nums, int i, int sum, int maxi)
    {
        if (i >= nums.size())
        {
            return 0;
        }
        int include = nums[i] + solve(nums, i + 2, sum, maxi);
        int exclude = solve(nums, i + 1, sum, maxi);
        return max(include, exclude);
    }

    // Top-Down DP
    int solve(vector<int> &nums, int i, int sum, int maxi, vector<int> &dp)
    {
        if (i >= nums.size())
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        int include = nums[i] + solve(nums, i + 2, sum, maxi, dp);
        int exclude = solve(nums, i + 1, sum, maxi, dp);
        return dp[i] = max(include, exclude);
    }

    // Bottom - Up DP
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp1(n + 1);
        vector<int> dp2(n + 1);
        dp1[0] = 0;
        dp1[1] = nums[0];
        dp2[0] = 0;
        dp2[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            if (i == n)
            {
                dp1[i] = dp1[i - 1];
            }
            else
            {
                dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i - 1]);
            }
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i - 1]);
        }
        return max(dp1[n], dp2[n]);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        vector<int> temp1;
        vector<int> temp2;
        if (n == 1)
        {
            return nums[0];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            // Exclude the first house and start from the second house
            if (i != 0)
            {
                temp1.push_back(nums[i]);
            }
            // Exclude the last house
            if (i != n - 1)
            {
                temp2.push_back(nums[i]);
            }
        }
        int exclude_first = solve(temp1, 0, 0, INT_MIN, dp);
        // Reset the dp array for the second pass
        dp.assign(n + 1, -1);
        int exclude_last = solve(temp2, 0, 0, INT_MIN, dp);
        return max(exclude_first, exclude_last);
    }
};
