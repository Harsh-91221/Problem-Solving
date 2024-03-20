int Solution::findMedian(vector<vector<int>> &A)
{
    int s = A.size();
    int e = A[0].size();
    int k = (s * e + 1) / 2;
    int a = INT_MAX;
    int b = INT_MIN;
    for (int i = 0; i < s; i++)
    {
        a = min(a, A[i][0]);
        b = max(b, A[i][e - 1]);
    }
    while (a < b)
    {
        int mid = a + (b - a) / 2;
        int count = 0;
        for (int i = 0; i < s; i++)
        {
            count += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        }
        if (count < k)
        {
            a = mid + 1;
        }
        else
        {
            b = mid;
        }
    }
    return a;
}
