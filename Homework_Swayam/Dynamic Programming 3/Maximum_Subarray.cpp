class Solution
{
public:
    // Recursion
    int solve(int i, vector<int> &nums, int &maxi)
    {
        if (i == nums.size() - 1)
        {
            maxi = max(maxi, nums[i]);
            return nums[i];
        }
        int sum = max(nums[i], nums[i] + solve(i + 1, nums, maxi));
        maxi = max(maxi, sum);
        return sum;
    }
    int maxSubArray(vector<int> &nums)
    {
        int maxi = INT_MIN;
        solve(0, nums, maxi);
        return maxi;
    }

    // DP
    int maxSubArray(vector<int> &nums)
    {
        int maxi = 0;
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        maxi = nums[0];
        for (int i = 1; i < n; i++)
        {
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }

    int maxSubArray(vector<int> &nums)
    {
        int maxi = 0;
        int n = nums.size();
        int prev = nums[0];
        maxi = nums[0];
        for (int i = 1; i < n; i++)
        {
            prev = max(nums[i], nums[i] + prev);
            maxi = max(maxi, prev);
        }
        return maxi;
    }
};