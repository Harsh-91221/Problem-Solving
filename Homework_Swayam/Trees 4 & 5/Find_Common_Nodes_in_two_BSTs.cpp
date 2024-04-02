class Solution
{
public:
    void solve(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        solve(root->left, ans);
        ans.push_back(root->data);
        solve(root->right, ans);
    }
    vector<int> findCommon(Node *root1, Node *root2)
    {
        unordered_map<int, int> mp;
        vector<int> v1, v2;
        solve(root1, v1);
        solve(root2, v2);
        vector<int> ans;
        if (v1.size() < v2.size())
        {
            swap(v1, v2);
        }
        int i = 0;
        int j = 0;
        while (i < v1.size() && j < v2.size())
        {
            if (v1[i] == v2[j])
            {
                ans.push_back(v1[i]);
                i++;
                j++;
            }
            else if (v2[j] > v1[i])
            {
                while (v2[j] > v1[i] && i < v1.size())
                {
                    i++;
                }
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};
