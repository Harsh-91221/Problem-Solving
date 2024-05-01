class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));
        dis[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty())
        {
            auto a = pq.top();
            pq.pop();
            int diff = a.first;
            int row = a.second.first;
            int col = a.second.second;
            if (row == n - 1 && col == m - 1)
            {
                return diff;
            }
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                {
                    int newEffort = max(abs(heights[row][col] - heights[nrow][ncol]), diff);
                    if (newEffort < dis[nrow][ncol])
                    {
                        dis[nrow][ncol] = newEffort;
                        pq.push({newEffort, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};