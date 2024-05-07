class Solution
{
public:
    int n;
    // Recursion
    int solve(int i, vector<vector<int>> &questions)
    {
        if (i >= n)
        {
            return 0;
        }
        int taken = questions[i][0] + solve(i + 1 + questions[i][1], questions);
        int not_taken = solve(i + 1, questions);
        return max(taken, not_taken);
    }

    // Top - Down DP
    long long solve(int i, vector<vector<int>> &questions, vector<long long> &dp)
    {
        if (i >= n)
        {
            return 0;
        }
        if (dp[i] != -1)
        {
            return dp[i];
        }
        long long taken = questions[i][0] + solve(i + 1 + questions[i][1], questions, dp);
        long long not_taken = solve(i + 1, questions, dp);
        return dp[i] = max(taken, not_taken);
    }

    // Bottom - Up DP
    long long solve(vector<vector<int>> &questions, vector<long long> &dp)
    {
        if (n == 1)
        {
            return questions[0][0];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = max(questions[i][0] + dp[i + questions[i][1] + 1], dp[i + 1]);
        }
        return dp[0];
    }
    long long mostPoints(vector<vector<int>> &questions)
    {
        n = questions.size();
        vector<long long> dp(200001, 0);
        return solve(questions, dp);
    }
};