class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int n = nums.size();
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
            {
                int right = mid;
                while (right + 1 < n && nums[right + 1] == target)
                {
                    right++;
                }
                int left = mid;
                while (left - 1 >= 0 && nums[left - 1] == target)
                {
                    left--;
                }
                return {left, right};
            }
            else if (nums[mid] < target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return {-1, -1};
    }
};