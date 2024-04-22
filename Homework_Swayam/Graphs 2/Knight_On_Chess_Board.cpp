int Solution::knew_ight(int A, int B, int C, int D, int E, int F)
{
    vector<vector<int>> grid(A + 1, vector<int>(B + 1));
    vector<vector<bool>> visited(A + 1, vector<bool>(B + 1, false));
    queue<pair<int, pair<int, int>>> q;
    visited[C][D] = true;
    q.push({0, {C, D}});
    int cnt = 0;
    while (!q.empty())
    {
        int count = q.front().first;
        int ci = q.front().second.first;
        int cj = q.front().second.second;
        if (ci == E and cj == F)
        {
            return count;
        }
        q.pop();
        int di[] = {-2, -2, 2, 2, -1, 1, -1, 1};
        int dj[] = {-1, 1, -1, 1, 2, 2, -2, -2};
        for (int k = 0; k < 8; k++)
        {
            int new_i = ci + di[k];
            int new_j = cj + dj[k];
            if (new_i >= 1 and new_j >= 1 and new_i <= A and new_j <= B and !visited[new_i][new_j])
            {
                visited[new_i][new_j] = true;
                q.push({count + 1, {new_i, new_j}});
            }
        }
    }
    return -1;
}