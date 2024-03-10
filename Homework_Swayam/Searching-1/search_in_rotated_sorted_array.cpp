class Solution
{
public:
    int pivot(vector<int> &nums, int s, int e)
    {
        while (s <= e)
        {
            if (s == e)
            {
                return s;
            }
            int mid = s + (e - s) / 2;
            if (mid - 1 >= s && nums[mid] < nums[mid - 1])
            {
                return mid - 1;
            }
            else if (mid + 1 <= e && nums[mid] > nums[mid + 1])
            {
                return mid;
            }
            if (nums[s] >= nums[mid])
            {
                e = mid;
            }
            else
            {
                s = mid + 1;
            }
        }
        return s;
    }
    int binaryS(vector<int> &nums, int target, int s, int e)
    {
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int pivotIndex = pivot(nums, 0, nums.size() - 1);
        int ans = 0;
        if (target >= nums[0] && nums[pivotIndex] >= target)
        {
            ans = binaryS(nums, target, 0, pivotIndex);
        }
        else
        {
            ans = binaryS(nums, target, pivotIndex + 1, nums.size() - 1);
        }
        return ans;
    }
};