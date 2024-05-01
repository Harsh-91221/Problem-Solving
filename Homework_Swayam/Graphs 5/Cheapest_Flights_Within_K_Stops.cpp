class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];
        for (auto a : flights)
        {
            adj[a[0]].push_back({a[1], a[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        // stops,{src,dest}
        q.push({0, {src, 0}});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while (!q.empty())
        {
            auto a = q.front();
            q.pop();
            int stops = a.first;
            int node = a.second.first;
            int cost = a.second.second;
            if (stops > k)
            {
                continue;
            }
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edgeW = it.second;
                if (cost + edgeW < dist[adjNode] && stops <= k)
                {
                    dist[adjNode] = cost + edgeW;
                    q.push({stops + 1, {adjNode, cost + edgeW}});
                }
            }
        }
        if (dist[dst] == INT_MAX)
        {
            return -1;
        }
        return dist[dst];
    }
};
