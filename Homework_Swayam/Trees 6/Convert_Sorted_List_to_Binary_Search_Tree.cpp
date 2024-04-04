/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *convert(ListNode *start, ListNode *end)
    {
        if (start == end)
        {
            return NULL;
        }
        ListNode *slow = start;
        ListNode *fast = start;
        while (fast != end && fast->next != end)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *newnode = new TreeNode(slow->val);
        newnode->left = convert(start, slow);
        newnode->right = convert(slow->next, end);
        return newnode;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (head == NULL)
        {
            return NULL;
        }
        return convert(head, NULL);
    }
};