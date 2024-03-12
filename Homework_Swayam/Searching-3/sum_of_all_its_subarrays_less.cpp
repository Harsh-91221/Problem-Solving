#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int> &a, int mid, int &s)
{
    int sum = 0;
    for (int i = 0; i < mid; i++)
    {
        sum += a[i];
    }
    if (sum > s)
    {
        return false;
    }
    int i = 0, j = mid;
    while (j < a.size())
    {
        sum -= a[i];
        sum += a[j];
        i++;
        j++;
        if (sum > s)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    int ans = 0, low = 0, high = n;
    while (low <= high)
    {
        long long mid = (low + high) / 2;
        bool flag = possible(a, mid, s);
        if (flag == true)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    cout << ans << endl;
    return 0;
}