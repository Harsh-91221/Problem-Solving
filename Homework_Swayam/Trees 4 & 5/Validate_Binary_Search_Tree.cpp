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
    bool solve(TreeNode *root, long long low, long long high)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->val > low && root->val < high)
        {
            bool leftans = solve(root->left, low, root->val);
            bool rightans = solve(root->right, root->val, high);
            return leftans && rightans;
        }
        else
        {
            return false;
        }
    }
    bool isValidBST(TreeNode *root)
    {
        long long low = LONG_MIN;
        long long high = LONG_MAX;
        return solve(root, low, high);
    }
};