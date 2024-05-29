class Solution
{
public:
    int n, m;
    //Recursion
    int solve(int i, int j, vector<int> &nums, vector<int> &multipliers)
    {
        if (j >= m)
        {
            return 0;
        }
        int left = solve(i + 1, j + 1, nums, multipliers) + nums[i] * multipliers[j];
        int right = solve(i, j + 1, nums, multipliers) + nums[n - (j - i) - 1] * multipliers[j];
        return max(left, right);
    }

    // DP
    int solve(int i, int j, vector<int> &nums, vector<int> &multipliers, vector<vector<int>> &dp)
    {
        if (j >= m)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int left = solve(i + 1, j + 1, nums, multipliers, dp) + nums[i] * multipliers[j];
        int right = solve(i, j + 1, nums, multipliers, dp) + nums[n - (j - i) - 1] * multipliers[j];
        return dp[i][j] = max(left, right);
    }
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        n = nums.size();
        m = multipliers.size();
        return solve(0, 0, nums, multipliers);
    }
};