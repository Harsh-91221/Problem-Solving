class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int s = 0;
        int e = nums.size() - 1;
        int n = nums.size();
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (mid - 1 >= 0 && nums[mid] == nums[mid - 1])
            {
                if (mid % 2 != 0)
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
            else if (mid + 1 < n && nums[mid] == nums[mid + 1])
            {
                if (mid % 2 == 0)
                {
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
            else
            {
                return nums[mid];
            }
        }
        return 0;
    }
};