class Solution
{
public:
    // Recursion
    //  int solve(int i,int j,string word1, string word2)
    //  {
    //      if(i<0)
    //      {
    //          return j+1;
    //      }
    //      if(j<0)
    //      {
    //          return i+1;
    //      }
    //      if(word1[i]==word2[j])
    //      {
    //          return solve(i-1,j-1,word1,word2);
    //      }
    //      return 1+min({solve(i-1,j,word1,word2),solve(i,j-1,word1,word2),solve(i-1,j-1,word1,word2)});
    //  }

    // Top-Down DP
    // int solve(int i, int j, string word1, string word2, vector<vector<int>> &dp)
    // {
    //     if (i == 0)
    //     {
    //         return j;
    //     }
    //     if (j == 0)
    //     {
    //         return i;
    //     }
    //     if (dp[i][j] != -1)
    //     {
    //         return dp[i][j];
    //     }
    //     if (word1[i - 1] == word2[j - 1])
    //     {
    //         return dp[i][j] = solve(i - 1, j - 1, word1, word2, dp);
    //     }
    //     return dp[i][j] = 1 + min({solve(i - 1, j, word1, word2, dp), solve(i, j - 1, word1, word2, dp), solve(i - 1, j - 1, word1, word2, dp)});
    // }

    // Bottom - Up DP
    // int solve(int i, int j, string word1, string word2, vector<vector<int>> &dp)
    // {
    //     for (int i = 0; i <= word1.size(); i++)
    //     {
    //         dp[i][0] = i;
    //     }
    //     for (int j = 0; j <= word2.size(); j++)
    //     {
    //         dp[0][j] = j;
    //     }
    //     for (int i = 1; i <= word1.size(); i++)
    //     {
    //         for (int j = 1; j <= word2.size(); j++)
    //         {
    //             if (word1[i - 1] == word2[j - 1])
    //             {
    //                 dp[i][j] = dp[i-1][j-1];
    //             }
    //             else
    //             {
    //                 dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
    //             }
    //         }
    //     }
    //     return dp[i][j];
    // }

    // Space Optimized
    int solve(string word1, string word2, vector<int> &curr, vector<int> &prev)
    {
        for (int i = 0; i <= word2.size(); i++)
        {
            prev[i] = i;
        }
        for (int i = 1; i <= word1.size(); i++)
        {
            curr[0] = i;
            for (int j = 1; j <= word2.size(); j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    curr[j] = prev[j - 1];
                }

                else
                {
                    curr[j] = 1 + min({prev[j], curr[j - 1], prev[j - 1]});
                }
            }
            prev = curr;
        }
        return prev[word2.size()];
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        vector<int> curr(m + 1);
        vector<int> prev(m + 1);
        return solve(word1, word2, curr, prev);
    }
};