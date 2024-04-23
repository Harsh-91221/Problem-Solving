class Solution
{
public:
    vector<int> topo(unordered_map<int, vector<int>> &adj, int numCourses, vector<int> &indegree)
    {
        queue<int> q;
        vector<int> ans;
        int count = 0;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                ans.push_back(i);
                count++;
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int &a : adj[u])
            {
                indegree[a]--;
                if (indegree[a] == 0)
                {
                    ans.push_back(a);
                    count++;
                    q.push(a);
                }
            }
        }
        return count == numCourses ? ans : vector<int>{};
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for (auto a : prerequisites)
        {
            int u = a[0];
            int v = a[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        return topo(adj, numCourses, indegree);
    }
};