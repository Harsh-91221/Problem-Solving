int help(int root, vector<vector<int>> &adj, int &ans)
{
    int maxi = 0;
    for (auto a : adj[root])
    {
        int temp = help(a, adj, ans);
        ans = max(ans, maxi + temp);
        maxi = max(maxi, temp);
    }
    return 1 + maxi;
}
int Solution::solve(vector<int> &A)
{
    vector<vector<int>> adj(A.size(), vector<int>(0));
    int root = -1;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == -1)
        {
            root = i;
            continue;
        }
        adj[A[i]].push_back(i);
    }
    int ans = 0;
    help(root, adj, ans);
    return ans;
}
