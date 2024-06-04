class Solution
{
public:
    int n;
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
        n = cardPoints.size();
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
            vector<vector<int>> dp(k + 1, vector<int>(k + 1, -1));
            return solve(cardPoints, k, 0, cardPoints.size() - 1, dp);
        }
    }
};