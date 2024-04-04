class Solution
{
public:
    Node *prev = NULL;
    Node *head = NULL;
    Node *bTreeToCList(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        bTreeToCList(root->left);
        if (prev == NULL)
        {
            head = root;
        }
        else
        {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        bTreeToCList(root->right);
        prev->right = head;
        head->left = prev;
        return head;
    }
};