class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.length();
        int maxi = INT_MIN;
        int j = 0;
        int window = 0;
        for (int i = 0; i < n; i++)
        {
            window += abs(s[i] - t[i]);
            while (window > maxCost)
            {
                window -= abs(s[j] - t[j]);
                j++;
            }
            maxi = max(maxi, i - j + 1);
        }
        return maxi;
    }
};