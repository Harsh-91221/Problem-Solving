class Solution
{
public:
    bool BST(Node *root, int low, int high)
    {
        if (root == NULL)
        {
            return true;
        }
        if (root->data > low && root->data < high)
        {
            bool leftans = BST(root->left, low, root->data);
            bool rightans = BST(root->right, root->data, high);
            return leftans && rightans;
        }
        else
        {
            return false;
        }
    }
    int size(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return size(root->left) + size(root->right) + 1;
    }
    int largestBst(Node *root)
    {
        if (BST(root, INT_MIN, INT_MAX))
        {
            return size(root);
        }
        return max(largestBst(root->left), largestBst(root->right));
    }
};