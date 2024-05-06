class Solution
{
public:
    // void dfs(int u,int v,int &ok,vector<int> &vis,vector<int> adj[])
    // {
    //     if(ok==0)
    //     {
    //         return;
    //     }
    //     if(u==v)
    //     {
    //         ok=0;
    //         return;
    //     }
    //     vis[u]=1;
    //     for(auto a:adj[u])
    //     {
    //         if(!vis[a])
    //         {
    //             dfs(a,v,ok,vis,adj);
    //         }
    //     }
    // }
    // vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
    //     vector<int> adj[n];
    //     int m=requests.size();
    //     vector<bool> ans(m,0);
    //     for(int i=0;i<m;i++)
    //     {
    //         int u=requests[i][0];
    //         int v=requests[i][1];
    //         int ok=1;
    //         adj[u].push_back(v);
    //         adj[v].push_back(u);
    //         for(auto a:restrictions)
    //         {
    //             vector<int> vis(n,0);
    //             int u=a[0];
    //             int v=a[1];
    //             dfs(u,v,ok,vis,adj);
    //             if(ok==0)
    //             {
    //                 break;
    //             }
    //         }
    //         if(ok)
    //         {
    //             ans[i]=1;
    //         }
    //         else
    //         {
    //             adj[u].pop_back();
    //             adj[v].pop_back();
    //         }
    //     }
    //     return ans;
    // }
    vector<int> par, rank;
    int find(int u)
    {
        if (par[u] == u)
        {
            return u;
        }
        return par[u] = find(par[u]);
    }
    void Union(int u, int v)
    {
        int par_u = find(u);
        int par_v = find(v);
        int rank_u = rank[par_u];
        int rank_v = rank[par_v];
        if (rank_u < rank_v)
        {
            par[par_u] = par_v;
        }
        else if (rank_v < rank_u)
        {
            par[par_v] = par_u;
        }
        else
        {
            par[par_v] = par_u;
            rank[u]++;
        }
    }
    bool connected(int u, int v)
    {
        int par_u = find(u);
        int par_v = find(v);
        if (par_u == par_v)
        {
            return 1;
        }
        return 0;
    }
    vector<bool> friendRequests(int n, vector<vector<int>> &restrictions, vector<vector<int>> &requests)
    {
        par.resize(n);
        for (int i = 0; i < n; i++)
        {
            par[i] = i;
        }
        rank.resize(n, 0);
        int m = requests.size();
        vector<bool> ans(m, 0);
        for (int i = 0; i < m; i++)
        {
            int u = requests[i][0], v = requests[i][1];
            bool ok = 1;
            vector<int> tmp_par = par;
            vector<int> tmp_rank = rank;
            Union(u, v);
            for (auto &res : restrictions)
            {
                if (connected(res[0], res[1]))
                {
                    ok = 0;
                    break;
                }
            }
            if (ok)
            {
                ans[i] = 1;
            }
            else
            {
                par = tmp_par;
                rank = tmp_rank;
            }
        }
        return ans;
    }
};