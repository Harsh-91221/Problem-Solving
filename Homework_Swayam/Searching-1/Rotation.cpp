class Solution
{
public:
    int findKRotation(int arr[], int n)
    {
        int s = 0;
        int e = n - 1;
        if (arr[s] < arr[e])
        {
            return 0;
        }
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (arr[0] > arr[mid])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return s;
    }
};