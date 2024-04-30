class Solution
{
public:
    vector<int> dis, vis;
    unordered_map<int, vector<pair<int, int>>> mp;
    void dijk(int src, vector<int> &disappear)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while (!pq.empty())
        {
            pair<int, int> temp = pq.top();
            pq.pop();
            int best = temp.first;
            int node = temp.second;
            if (vis[node] || best >= disappear[node])
            {
                continue;
            }
            dis[node] = best;
            vis[node] = 1;
            for (auto a : mp[node])
            {
                if (vis[a.first] == 0)
                {
                    pq.push({best + a.second, a.first});
                }
            }
        }
    }
    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
    {
        for (auto a : edges)
        {
            int u = a[0];
            int v = a[1];
            int w = a[2];
            mp[u].push_back({v, w});
            mp[v].push_back({u, w});
        }
        dis = vector<int>(n, -1);
        vis = vector<int>(n, 0);
        dijk(0, disappear);
        return dis;
    }
};