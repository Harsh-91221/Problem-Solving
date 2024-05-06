class Solution
{
public:
    int findParent(int n, vector<int> p)
    {
        if (n == p[n])
        {
            return n;
        }
        return findParent(p[n], p);
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<int> parent(1001, 0);
        for (int i = 0; i < edges.size(); i++)
        {
            parent[i] = i;
        }
        vector<int> ans;
        for (auto a : edges)
        {
            int n1 = a[0];
            int n2 = a[1];
            int p1 = findParent(n1, parent);
            int p2 = findParent(n2, parent);
            if (p1 == p2)
            {
                ans = a;
            }
            parent[p1] = p2;
        }
        return ans;
    }
};