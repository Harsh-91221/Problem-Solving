class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        map<int, int> mp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto i = q.front();
            q.pop();
            Node *node = i.first;
            int line = i.second;
            if (mp.find(line) == mp.end())
            {
                mp[line] = node->data;
            }
            if (node->left != NULL)
            {
                q.push({node->left, line - 1});
            }
            if (node->right != NULL)
            {
                q.push({node->right, line + 1});
            }
        }
        for (auto i : mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
