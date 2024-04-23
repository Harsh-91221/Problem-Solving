class Solution
{
public:
    void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        for (auto a : adj[node])
        {
            if (!vis[a])
            {
                dfs(a, vis, adj);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> ans(n);
        vector<vector<int>> adj(n);
        for (auto a : edges)
        {
            int u = a[0];
            int v = a[1];
            adj[u].push_back(v);
        }
        for (int i = 0; i < n; i++)
        {
            vector<bool> vis(n, false);
            dfs(i, vis, adj);
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                if (vis[j])
                {
                    ans[j].push_back(i);
                }
            }
        }
        return ans;
    }
};