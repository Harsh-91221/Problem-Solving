class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> count(n, 1);
        vector<int> t(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    if (t[j] + 1 == t[i])
                    {
                        count[i] += count[j];
                    }
                    else if (t[j] + 1 > t[i])
                    {
                        t[i] = t[j] + 1;
                        count[i] = count[j];
                    }
                }
            }
        }
        int maxi = *max_element(t.begin(), t.end());
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (t[i] == maxi)
            {
                ans += count[i];
            }
        }
        return ans;
    }
};