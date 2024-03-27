class Solution
{
public:
    Node *LCA(Node *root, int a, int b)
    {
        if (root == NULL)
        {
            return root;
        }
        if (root->data == a || root->data == b)
        {
            return root;
        }
        Node *lefty = LCA(root->left, a, b);
        Node *righty = LCA(root->right, a, b);
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
    void find(Node *root, int &count, int val)
    {
        int temp = 0;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                Node *curr = q.front();
                q.pop();
                if (curr->data == val)
                {
                    count = temp;
                    return;
                }
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            temp++;
        }
    }
    int findDist(Node *root, int a, int b)
    {
        Node *lca = LCA(root, a, b);
        int dis_a = 0;
        int dis_b = 0;
        find(lca, dis_a, a);
        find(lca, dis_b, b);
        return dis_a + dis_b;
    }
};