class Solution
{
public:
    void bfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> delrow = {-1, 0, 0, 1};
        vector<int> delcol = {0, -1, 1, 0};
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
                {
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    bfs(i, j, vis, grid);
                    count++;
                }
            }
        }
        return count;
    }
};