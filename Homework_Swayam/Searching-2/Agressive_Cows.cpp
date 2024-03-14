bool solve(vector<int> &stalls, int mid, int k)
{
    int init = stalls[0];
    int cowscount = 1;
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - init >= mid)
        {
            cowscount++;
            init = stalls[i];
        }
        if (cowscount >= k)
        {
            return true;
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    for (int i = 1; i < stalls.size(); i++)
    {
        s = min(s, abs(stalls[i] - stalls[i - 1]));
    }
    int e = *max_element(stalls.begin(), stalls.end());
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (solve(stalls, mid, k))
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return e;
}