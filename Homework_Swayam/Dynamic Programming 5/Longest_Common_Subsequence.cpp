class Solution
{
public:
    int m, n;
    // Recursion
    int solve(int i, int j, string text1, string text2)
    {
        if (i >= m || j >= n)
        {
            return 0;
        }
        int ans = 0;
        if (text1[i] == text2[j])
        {
            ans = 1 + solve(i + 1, j + 1, text1, text2);
        }
        else
        {
            ans = max(solve(i + 1, j, text1, text2), solve(i, j + 1, text1, text2));
        }
        return ans;
    }

    // Top - Down DP
    int solve(int i, int j, string text1, string text2, vector<vector<int>> &dp)
    {
        if (i >= m || j >= n)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = 0;
        if (text1[i] == text2[j])
        {
            ans = 1 + solve(i + 1, j + 1, text1, text2, dp);
        }
        else
        {
            ans = max(solve(i + 1, j, text1, text2, dp), solve(i, j + 1, text1, text2, dp));
        }
        return dp[i][j] = ans;
    }

    //Bottom - Up DP
    int longestCommonSubsequence(string text1, string text2)
    {
        m = text1.size();
        n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int ans = 0;
                if (text1[i] == text2[j])
                {
                    ans = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    ans = max(dp[i + 1][j], dp[i][j + 1]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};