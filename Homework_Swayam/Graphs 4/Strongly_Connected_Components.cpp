class Solution
{
public:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &s)
    {
        vis[node] = 1;
        for (auto a : adj[node])
        {
            if (!vis[a])
            {
                dfs(a, vis, adj, s);
            }
        }
        s.push(node);
    }

    void dfss(int node, vector<int> &vis, vector<vector<int>> &adj)
    {
        vis[node] = 1;
        for (auto a : adj[node])
        {
            if (!vis[a])
            {
                dfss(a, vis, adj);
            }
        }
    }

    int kosaraju(int V, vector<vector<int>> &adj)
    {
        vector<int> vis(V, 0);
        stack<int> s;

        // First DFS to fill the stack
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, s);
            }
        }

        // Transpose the graph
        vector<vector<int>> adjT(V);
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0;
            for (auto a : adj[i])
            {
                adjT[a].push_back(i);
            }
        }

        // Second DFS on the transposed graph
        int scc = 0;
        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            if (!vis[node])
            {
                scc++;
                dfss(node, vis, adjT);
            }
        }
        return scc;
    }
};