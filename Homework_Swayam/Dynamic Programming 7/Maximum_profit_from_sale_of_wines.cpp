#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
int maxProfit(vector<int> &nums, int s, int e, int year)
{
    if (s > e)
    {
        return 0;
    }
    string ans = to_string(s) + "," + to_string(e) + "," + to_string(year);
    if (mp.find(ans) != mp.end())
    {
        return mp[ans];
    }
    int start = year * nums[s] + maxProfit(nums, s + 1, e, year + 1);
    int end = year * nums[e] + maxProfit(nums, s, e - 1, year + 1);
    mp[ans] = max(start, end);
    return mp[ans];
}
int main()
{
    int n;
    cout << "Enter the number of elements ";
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << maxProfit(arr, 0, n - 1, 1);
    return 0;
}