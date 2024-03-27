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
    void solve(TreeNode *root, long long sum, int targetSum, int &count)
    {
        if (root == NULL)
        {
            return;
        }
        sum += root->val;
        if (sum == targetSum)
        {
            count++;
        }
        solve(root->left, sum, targetSum, count);
        solve(root->right, sum, targetSum, count);
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
        {
            return NULL;
        }
        int count = 0;
        solve(root, 0, targetSum, count);
        count += pathSum(root->left, targetSum);
        count += pathSum(root->right, targetSum);
        return count;
    }
};