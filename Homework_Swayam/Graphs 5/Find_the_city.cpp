class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (auto a : edges)
        {
            dist[a[0]][a[1]] = a[2];
            dist[a[1]][a[0]] = a[2];
        }
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                    {
                        continue;
                    }
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int minCityCount = INT_MAX;
        int cityNo = -1;
        for (int city = 0; city < n; city++)
        {
            int count = 0;
            for (int adjCity = 0; adjCity < n; adjCity++)
            {
                if (dist[city][adjCity] <= distanceThreshold)
                {
                    count++;
                }
            }
            if (count <= minCityCount)
            {
                minCityCount = count;
                cityNo = city;
            }
        }
        return cityNo;
    }
};