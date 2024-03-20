#include <climits>
int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k)
{
    int n1 = n;
    int n2 = m;
    if (n1 > n2)
    {
        return kthElement(arr2, arr1, n2, n1, k);
    }
    int s = max(k - n2, 0);
    int e = min(k, n1);
    int left = k;
    n = n1 + n2;
    while (s <= e)
    {
        int mid1 = s + (e - s) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;
        if (mid1 < n1)
        {
            r1 = arr1[mid1];
        }
        if (mid2 < n2)
        {
            r2 = arr2[mid2];
        }
        if (mid1 - 1 >= 0)
        {
            l1 = arr1[mid1 - 1];
        }
        if (mid2 - 1 >= 0)
        {
            l2 = arr2[mid2 - 1];
        }
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > l2)
        {
            e = mid1 - 1;
        }
        else
        {
            s = mid1 + 1;
        }
    }
    return 0;
}