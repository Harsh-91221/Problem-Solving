class Solution
{
public:
    bool check(int start, vector<int> &colors, vector<vector<int>> &graph)
    {
        queue<int> q;
        q.push(start);
        colors[start] = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto a : graph[node])
            {
                if (colors[a] == -1)
                {
                    colors[a] = !colors[node];
                    q.push(a);
                }
                else if (colors[a] == colors[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> colors(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (colors[i] == -1 && !check(i, colors, graph))
            {
                return false;
            }
        }
        return true;
    }
};