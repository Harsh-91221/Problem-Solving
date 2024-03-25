class Solution
{
public:
    int odd = 0;
    int even = 0;
    void solve(Node *root, int level)
    {
        if (root == NULL)
        {
            return;
        }
        if (level % 2 == 0)
        {
            even += root->data;
        }
        else
        {
            odd += root->data;
        }
        solve(root->left, level + 1);
        solve(root->right, level + 1);
    }
    int getLevelDiff(Node *root)
    {
        solve(root, 1);
        return odd - even;
    }
};
