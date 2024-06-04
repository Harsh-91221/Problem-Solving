#define ll long long
class Solution
{
public:
    int shortestSubarray(vector<int> &a, int k)
    {
        ll n = a.size();
        ll ans = LLONG_MAX;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            if (sum >= k)
            {
                ans = min(ans, i * 1LL + 1);
            }
            while (!pq.empty() && sum - pq.top().first >= k)
            {
                ans = min(ans, i - pq.top().second);
                pq.pop();
            }
            pq.push({sum, i});
        }
        return ans == INT_MAX ? -1 : ans;
    }
};