class Solution
{
public:
    bool solve(vector<int> &bloomDay, long long mid, long long m, long long k)
    {
        long long count = 0;
        long long bouquet = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= mid)
            {
                count++;
            }
            else
            {
                bouquet += (count / k);
                count = 0;
            }
        }
        bouquet += (count / k);
        if (bouquet >= m)
        {
            return true;
        }
        return false;
    }
    int minDays(vector<int> &bloomDay, long long m, long long k)
    {
        long long value = m * k;
        if (value > bloomDay.size())
        {
            return -1;
        }
        long long mini = *min_element(bloomDay.begin(), bloomDay.end());
        long long maxi = *max_element(bloomDay.begin(), bloomDay.end());
        while (mini <= maxi)
        {
            long long mid = mini + (maxi - mini) / 2;
            if (solve(bloomDay, mid, m, k))
            {
                maxi = mid - 1;
            }
            else
            {
                mini = mid + 1;
            }
        }
        return mini;
    }
};