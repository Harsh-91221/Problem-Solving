class Solution
{
public:
    // Recursion
    bool help(int i, int j, string s, int n, string p, int m)
    {
        if (i < 0 && j < 0)
        {
            return true;
        }
        if (i >= 0 && j < 0)
        {
            return false;
        }
        if (i < 0 && j >= 0)
        {
            for (int k = 0; k <= j; k++)
            {
                if (p[k] != '*')
                {
                    return false;
                }
            }
            return true;
        }
        if (s[i] == p[j] || p[j] == '?')
        {
            return help(i - 1, j - 1, s, n, p, m);
        }
        else if (p[j] == '*')
        {
            return help(i - 1, j, s, n, p, m) | help(i, j - 1, s, n, p, m);
        }
        return false;
    }

    // DP
    bool help(int i, int j, string &s, int n, string &p, int m, vector<vector<int>> &dp)
    {
        if (i < 0 && j < 0)
        {
            return true;
        }
        if (j < 0 && i >= 0)
        {
            return false;
        }
        if (i < 0 && j >= 0)
        {
            for (int k = 0; k <= j; k++)
            {
                if (p[k] != '*')
                {
                    return false;
                }
            }
            return true;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (s[i] == p[j] || p[j] == '?')
        {
            return dp[i][j] = help(i - 1, j - 1, s, n, p, m, dp);
        }
        else if (p[j] == '*')
        {
            return dp[i][j] = help(i - 1, j, s, n, p, m, dp) | help(i, j - 1, s, n, p, m, dp);
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        int i = n - 1, j = m - 1;
        return help(i, j, s, n, p, m);
    }
};