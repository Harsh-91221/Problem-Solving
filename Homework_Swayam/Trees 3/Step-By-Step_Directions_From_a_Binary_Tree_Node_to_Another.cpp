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
    bool search(TreeNode *root, int target, string &s)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->val == target)
        {
            return true;
        }
        bool find1 = search(root->left, target, s += 'L');
        if (find1)
        {
            return true;
        }
        s.pop_back();
        bool find2 = search(root->right, target, s += 'R');
        if (find2)
        {
            return true;
        }
        s.pop_back();
        return false;
    }
    TreeNode *LCA(TreeNode *root, int startValue, int destValue)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->val == startValue || root->val == destValue)
        {
            return root;
        }
        TreeNode *lefty = LCA(root->left, startValue, destValue);
        TreeNode *righty = LCA(root->right, startValue, destValue);
        if (lefty != NULL && righty != NULL)
        {
            return root;
        }
        if (lefty)
        {
            return lefty;
        }
        if (righty)
        {
            return righty;
        }
        return NULL;
    }
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        TreeNode *temp = LCA(root, startValue, destValue);
        string str1, str2;
        search(temp, startValue, str1);
        search(temp, destValue, str2);
        for (auto &a : str1)
        {
            a = 'U';
        }
        return str1 + str2;
    }
};