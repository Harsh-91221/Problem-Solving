class Solution
{
public:
    int pivot(vector<int> &nums, int s, int e)
    {
        while (s <= e)
        {
            if (s == e)
            {
                return e;
            }
            int mid = s + (e - s) / 2;
            if (mid - 1 >= s && nums[mid - 1] > nums[mid])
            {
                return mid - 1;
            }
            if (mid <= e && nums[mid] > nums[mid + 1])
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
    int binarysearch(vector<int> &nums, int target, int s, int e)
    {
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] > target)
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
        int ans = 0;
        int pivotindex = pivot(nums, 0, nums.size() - 1);
        // WE HAVE TO COMPARE TARGET FROM THE FIRST ELEMENT
        if (target >= nums[0] && nums[pivotindex] >= target)
        {
            ans = binarysearch(nums, target, 0, pivotindex);
        }
        else
        {
            ans = binarysearch(nums, target, pivotindex + 1, nums.size() - 1);
        }
        return ans;
    }
};