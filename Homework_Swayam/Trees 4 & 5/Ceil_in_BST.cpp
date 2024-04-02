int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;
    int mini = INT_MAX;
    while (root != NULL && root->data != NULL)
    {
        if (root->data == input)
        {
            mini = root->data;
            break;
        }
        if (root->data > input)
        {
            mini = min(mini, root->data);
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    if (mini == INT_MAX)
    {
        return -1;
    }
    return mini;
}