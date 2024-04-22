class Solution
{
public:
    int n, m;
    bool isValid(int i, int j, vector<vector<int>> &grid)
    {
        return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1;
    }
    int orangesRotting(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        int time = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }
        if (fresh == 0)
        {
            return 0;
        }
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                pair<int, int> cur = q.front();
                q.pop();
                int x = cur.first;
                int y = cur.second;
                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (isValid(nx, ny, grid))
                    {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time - 1 : -1;
    }
};
