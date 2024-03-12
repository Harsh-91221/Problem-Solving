class Solution
{
public:
    bool solve(vector<int> &nums, int maxOperations, int penalty)
    {
        int reqOps = 0;
        for (auto a : nums)
        {
            int x = a / penalty;
            if (a % penalty == 0)
            {
                x--;
            }
            reqOps += x;
        }
        return reqOps <= maxOperations;
    }
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int s = 1;
        int e = *max_element(nums.begin(), nums.end());
        int ans = e;
        while (s <= e)
        {
            int penalty = s + (e - s) / 2;
            if (solve(nums, maxOperations, penalty))
            {
                ans = penalty;
                e = penalty - 1;
            }
            else
            {
                s = penalty + 1;
            }
        }
        return ans;
    }
};