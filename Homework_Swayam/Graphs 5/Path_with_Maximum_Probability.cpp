class Solution
{
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
    {
        unordered_map<int, vector<pair<int, double>>> mp;
        vector<double> ans(n, 0);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            mp[u].push_back({v, prob});
            mp[v].push_back({u, prob});
        }
        priority_queue<pair<double, int>> pq;
        ans[start_node] = 1;
        pq.push({1.0, start_node});
        while (!pq.empty())
        {
            double currProb = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            for (auto a : mp[currNode])
            {
                int adjNode = a.first;
                double adjProb = a.second;
                if (ans[adjNode] < currProb * adjProb)
                {
                    ans[adjNode] = currProb * adjProb;
                    pq.push({ans[adjNode], adjNode});
                }
            }
        }
        return ans[end_node];
    }
};