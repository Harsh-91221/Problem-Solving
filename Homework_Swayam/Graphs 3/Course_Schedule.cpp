class Solution
{
public:
    bool topo(unordered_map<int, vector<int>> &adj, int numCourses, vector<int> &indegree)
    {
        queue<int> q;
        int count = 0;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
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
                    count++;
                    q.push(a);
                }
            }
        }
        return count == numCourses;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
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