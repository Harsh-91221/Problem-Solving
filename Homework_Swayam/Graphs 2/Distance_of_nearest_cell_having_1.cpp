class Solution
{
public:
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while (!q.empty())
        {
            int ni = q.front().first;
            int nj = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int new_i = ni + dx[k];
                int new_j = nj + dy[k];
                if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && ans[new_i][new_j] == -1)
                {
                    q.push({new_i, new_j});
                    ans[new_i][new_j] = ans[ni][nj] + 1;
                }
            }
        }
        return ans;
    }
};