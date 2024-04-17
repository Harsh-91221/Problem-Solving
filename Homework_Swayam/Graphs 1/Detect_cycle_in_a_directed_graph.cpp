class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool solve(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        for (auto a : adj[node])
        {
            if (!vis[a])
            {
                if (solve(a, adj, vis, pathVis))
                {
                    return true;
                }
            }
            else if (pathVis[a] == 1)
            {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (solve(i, adj, vis, pathVis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};