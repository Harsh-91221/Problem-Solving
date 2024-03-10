#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> query(q);
    for (int i = 0; i < q; i++)
    {
        cin >> query[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < q; i++)
    {
        int idx = n;
        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (a[mid] >= query[i])
            {
                idx = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        cout << n - idx << endl;
    }
    return 0;
}
