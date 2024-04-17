class Solution
{
public:
    bool solve(vector<vector<int>> &edges, int source, int destination, unordered_map<int, vector<int>> &mp, vector<bool> &vis)
    {
        if (source == destination)
        {
            return true;
        }
        if (vis[source] == true)
        {
            return false;
        }
        vis[source] = true;
        for (auto a : mp[source])
        {
            if (solve(edges, a, destination, mp, vis))
            {
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        unordered_map<int, vector<int>> mp;
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(source);
        vis[source] = true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            if (node == destination)
            {
                return true;
            }
            for (auto a : mp[node])
            {
                if (!vis[a])
                {
                    q.push(a);
                    vis[a] = true;
                }
            }
        }
        return false;
        // return solve(edges,source,destination,mp,vis);
    }
};