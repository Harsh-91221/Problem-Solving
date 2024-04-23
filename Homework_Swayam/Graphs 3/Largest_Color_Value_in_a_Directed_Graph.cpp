class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        unordered_map<int, vector<int>> adj;
        int n = colors.size();
        vector<int> indegree(n, 0);
        for (auto a : edges)
        {
            int u = a[0];
            int v = a[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int> q;
        vector<vector<int>> t(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                t[i][colors[i] - 'a'] = 1;
            }
        }
        int ans = 0;
        int count = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            count++;
            ans = max(ans, t[u][colors[u] - 'a']);
            for (int &a : adj[u])
            {
                for (int i = 0; i < 26; i++)
                {
                    t[a][i] = max(t[a][i], t[u][i] + (colors[a] - 'a' == i));
                }
                indegree[a]--;
                if (indegree[a] == 0)
                {
                    q.push(a);
                }
            }
        }
        return count < n ? -1 : ans;
    }
};