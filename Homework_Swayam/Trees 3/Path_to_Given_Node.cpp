/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool func(TreeNode *A, int B, vector<int> &ans)
{
    if (A == NULL)
    {
        return false;
    }
    ans.push_back(A->val);
    if (A->val == B)
    {
        return true;
    }
    if (func(A->left, B, ans) || func(A->right, B, ans))
    {
        return true;
    }
    ans.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode *A, int B)
{
    vector<int> ans;
    func(A, B, ans);
    return ans;
}
