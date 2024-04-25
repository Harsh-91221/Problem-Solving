class Solution
{
public:
    int ans = INT_MAX;
    void bfs(int src, vector<int> adj[], int n)
    {
        vector<int> distance(n, INT_MAX);
        vector<int> parent(n, -1);
        queue<int> q;
        distance[src] = 0;
        q.push(src);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto neighbour : adj[node])
            {
                if (distance[neighbour] == INT_MAX)
                {
                    distance[neighbour] = 1 + distance[node];
                    parent[neighbour] = node;
                    q.push(neighbour);
                }
                else if (parent[node] != neighbour && parent[neighbour] != node)
                {
                    ans = min(ans, distance[neighbour] + distance[node] + 1);
                }
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        vector<int> adj[n + 1];
        for (auto a : edges)
        {
            int u = a[0];
            int v = a[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i = 0; i < n; i++)
        {
            bfs(i, adj, n);
        }
        if (ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};