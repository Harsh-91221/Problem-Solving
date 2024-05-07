class Solution
{
public:
    // Recursion
    int solve(int n, vector<vector<int>> &mat, int rol, int col)
    {
        if (col >= n)
        {
            return 0;
        }
        int a = mat[rol][col] + max(solve(n, mat, 1, col + 2), solve(n, mat, 0, col + 2));
        int b = solve(n, mat, 1, col + 1);
        int c = solve(n, mat, 0, col + 1);
        return max({a, b, c});
    }

    // Top-Down DP
    int solve(int n, vector<vector<int>> &mat, int rol, int col, vector<vector<int>> &dp)
    {
        if (col >= n)
        {
            return 0;
        }
        if (dp[rol][col] != -1)
        {
            return dp[rol][col];
        }
        int a = mat[rol][col] + max(solve(n, mat, 1, col + 2, dp), solve(n, mat, 0, col + 2, dp));
        int b = solve(n, mat, 1, col + 1, dp);
        int c = solve(n, mat, 0, col + 1, dp);
        return dp[rol][col] = max({a, b, c});
    }

    // Bottom - Up DP
    int solve(int n, vector<vector<int>> &mat, vector<vector<int>> &dp)
    {
        dp[1][0] = max(mat[0][0], mat[1][0]);
        dp[2][0] = max(dp[1][0], max(mat[0][1], mat[1][1]));
        for (int i = 3; i <= n; i++)
        {
            int ans = max(mat[0][i - 1], mat[1][i - 1]);
            dp[i][0] = max(ans + dp[i - 2][0], dp[i - 1][0]);
        }
        return dp[n][0];
    }
    int maxSum(int N, vector<vector<int>> mat)
    {
        vector<vector<int>> dp(N, vector<int>(N + 1, -1));
        return max(solve(N, mat, 0, 0, dp), solve(N, mat, 1, 0, dp));
    }
};