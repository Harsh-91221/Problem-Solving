struct Node
{
    Node *links[2];
    int ew = 0;
};
class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(int n)
    {
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (n >> i) & 1;
            if (temp->links[bit] == NULL)
            {
                Node *newnode = new Node();
                temp->links[bit] = newnode;
            }
            temp = temp->links[bit];
            temp->ew++;
        }
        // temp->ew++;
    }
    int countpairs(Node *node, int ind, int num, int maxi)
    {
        if (node == NULL)
        {
            return 0;
        }
        if (ind < 0)
        {
            return node->ew;
        }
        int ans = 0;
        int numbit = (num >> ind) & 1;
        int maxibit = (maxi >> ind) & 1;
        if (numbit == 1)
        {
            if (maxibit == 1)
            {
                if (node->links[1] != NULL)
                {
                    ans += node->links[1]->ew;
                }
                ans += countpairs(node->links[0], ind - 1, num, maxi);
            }
            else
            {
                ans += countpairs(node->links[1], ind - 1, num, maxi);
            }
        }
        else
        {
            if (maxibit == 1)
            {
                if (node->links[0] != NULL)
                {
                    ans += node->links[0]->ew;
                }
                ans += countpairs(node->links[1], ind - 1, num, maxi);
            }
            else
            {
                ans += countpairs(node->links[0], ind - 1, num, maxi);
            }
        }
        return ans;
    }
};

class Solution
{
public:
    int countPairs(vector<int> &nums, int low, int high)
    {
        Trie T;
        int ans = 0;
        for (auto it : nums)
        {
            int r = T.countpairs(T.root, 31, it, high);
            int l = T.countpairs(T.root, 31, it, low - 1);
            ans += (r - l);
            cout << r << " " << l << endl;
            T.insert(it);
        }
        return ans;
    }
};