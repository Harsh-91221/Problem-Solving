/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void solve(TreeNode *root, TreeNode *&pre, TreeNode *&first, TreeNode *&second)
    {
        if (root == NULL)
        {
            return;
        }
        solve(root->left, pre, first, second);
        if (first == NULL && root->val < pre->val)
        {
            first = pre;
        }
        if (first != NULL && root->val < pre->val)
        {
            second = root;
        }
        pre = root;
        solve(root->right, pre, first, second);
    }
    void recoverTree(TreeNode *root)
    {
        TreeNode *pre = new TreeNode(INT_MIN);
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        solve(root, pre, first, second);
        swap(first->val, second->val);
    }
};