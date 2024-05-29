class Solution
{
public:
    // Recursion
    int solve(vector<int> &cardPoints, int k, int i, int j)
    {
        if (k == 0)
        {
            return 0;
        }
        return max(cardPoints[i] + solve(cardPoints, k - 1, i + 1, j), cardPoints[j] + solve(cardPoints, k - 1, i, j - 1));
    }

    // DP
    int solve(vector<int> &cardPoints, int k, int i, int j, vector<vector<int>> &dp)
    {
        if (k == 0)
        {
            return 0;
        }
        if (dp[i][n - j] != -1)
        {
            return dp[i][n - j];
        }
        return dp[i][n - j] = max(cardPoints[i] + solve(cardPoints, k - 1, i + 1, j, dp), cardPoints[j] + solve(cardPoints, k - 1, i, j - 1, dp));
    }
    int maxScore(vector<int> &cardPoints, int k)
    {
        vector<vector<int>> dp(n);
        if (k >= cardPoints.size())
        {
            int sum = 0;
            for (int i = 0; i < cardPoints.size(); i++)
            {
                sum += cardPoints[i];
            }
            return sum;
        }
        else
        {
            return solve(cardPoints, k, 0, cardPoints.size() - 1);
        }
    }
};

// Better
class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int c = n - k;
        int sum = 0;
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s += cardPoints[i];
        }
        for (int i = 0; i < c; i++)
        {
            sum += cardPoints[i];
        }
        int ans = sum;
        for (int i = c; i < n; i++)
        {
            sum += cardPoints[i] - cardPoints[i - c];
            ans = min(ans, sum);
        }
        return s - ans;
    }
};