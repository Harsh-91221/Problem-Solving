int maxDepth(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int right = maxDepth(root->right);
    int left = maxDepth(root->left);
    int ans = max(left, right) + 1;
    return ans;
}