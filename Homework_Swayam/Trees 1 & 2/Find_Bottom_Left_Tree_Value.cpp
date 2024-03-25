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
    // void solve(TreeNode *root,int currDepth,int &depth,int &currleft)
    // {
    //     if(root==NULL)
    //     {
    //         return;
    //     }
    //     if(currDepth>depth)
    //     {
    //         depth=currDepth;
    //         currleft=root->val;
    //     }
    //     solve(root->left,currDepth+1,depth,currleft);
    //     solve(root->right,currDepth+1,depth,currleft);
    // }
    int findBottomLeftValue(TreeNode *root)
    {
        // if(root==NULL)
        // {
        //     return NULL;
        // }
        // int depth=0;
        // int currleft=0;
        // solve(root,1,depth,currleft);
        // return currleft;
        if (root == NULL)
        {
            return NULL;
        }
        queue<TreeNode *> q;
        q.push(root);
        int leftAns = 0;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (i == 0)
                {
                    leftAns = curr->val;
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
        }
        return leftAns;
    }
};