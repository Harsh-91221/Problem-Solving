class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int s = 0;
        int e = nums.size() - 1;
        int n = nums.size();
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (mid - 1 >= 0 && mid + 1 < n && nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            else if (mid - 1 >= 0 && nums[mid] < nums[mid - 1])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return e;
    }
};