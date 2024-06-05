class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        // int maxi = 0;
        // int n = nums.size();
        // for (int i = 0; i < n; i++)
        // {
        //     int minElement = nums[i];
        //     int maxElement = nums[i];
        //     for (int j = i; j < n; j++)
        //     {
        //         minElement = min(minElement, nums[j]);
        //         maxElement = max(maxElement, nums[j]);
        //         if (maxElement - minElement <= limit)
        //         {
        //             maxi = max(maxi, j - i + 1);
        //         }
        //         else
        //         {
        //             break;
        //         }
        //     }
        // }
        // return maxi;
        int i = 0, j = 0;
        multiset<int> ms;
        for (j = 0; j < nums.size(); j++)
        {
            ms.insert(nums[j]);
            if (*ms.rbegin() - *ms.begin() > limit)
            {
                ms.erase(ms.find(nums[i]));
                i++;
            }
        }
        return j - i;
    }
};
