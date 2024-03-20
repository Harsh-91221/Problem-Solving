int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int s = 0, e = 10000;
    while (s < e)
    {
        int mid = s + (e - s) / 2;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count = count + (upper_bound(mat[i], mat[i] + n, mid) - mat[i]);
        }
        if (count < k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return s;
}
