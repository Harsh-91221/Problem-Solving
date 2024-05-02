class DSU
{
private:
    vector<int> parent;
    vector<int> rank;
    int components;
public:
    DSU(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1);
        components = n;
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent)
            return;

        if (rank[x_parent] > rank[y_parent])
        {
            parent[y_parent] = x_parent;
        }
        else if (rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent;
        }
        else
        {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
        components--;
    }
    bool isSingleComponent()
    {
        return components == 1;
    }
};
class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        DSU Alice(n);
        DSU Bob(n);
        sort(edges.begin(), edges.end(), [](const vector<int> &vec1, const vector<int> &vec2)
             { return vec1[0] > vec2[0]; });
        int edgeCount = 0;
        for (auto &edge : edges)
        {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];
            if (type == 3)
            {
                if (Alice.find(u) != Alice.find(v) || Bob.find(u) != Bob.find(v))
                {
                    Alice.Union(u, v);
                    Bob.Union(u, v);
                    edgeCount++;
                }
            }
            else if (type == 2)
            {
                if (Bob.find(u) != Bob.find(v))
                {
                    Bob.Union(u, v);
                    edgeCount++;
                }
            }
            else if (type == 1)
            {
                if (Alice.find(u) != Alice.find(v))
                {
                    Alice.Union(u, v);
                    edgeCount++;
                }
            }
        }
        if (Alice.isSingleComponent() && Bob.isSingleComponent())
        {
            return edges.size() - edgeCount;
        }

        return -1;
    }
};