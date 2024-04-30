class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(n + 1, INT_MAX);
        dis[k] = 0;
        pq.push({0, k});
        unordered_map<int, vector<pair<int, int>>> adj(n + 1);
        for (auto a : times)
        {
            int u = a[0];
            int v = a[1];
            int w = a[2];
            adj[u].push_back({v, w});
        }
        while (!pq.empty())
        {
            int tim = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto a : adj[node])
            {
                int edgeWeight = a.second;
                int adjacentNode = a.first;
                if (tim + edgeWeight < dis[adjacentNode])
                {
                    dis[adjacentNode] = tim + edgeWeight;
                    pq.push({dis[adjacentNode], adjacentNode});
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, dis[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};