class Solution
{
public:
    int findOnce(int arr[], int n)
    {
        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (mid + 1 <= n && arr[mid] == arr[mid + 1])
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
            else if (mid - 1 >= 0 && arr[mid] == arr[mid - 1])
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
            else
            {
                return arr[mid];
            }
        }
        return 0;
    }
};