struct TrieNode
{
    TrieNode *next[26] = {};
    int count = 0;
};
class Solution
{
    TrieNode root;
    public:
    void insert(string word)
    {
        auto node = &root;
        for (char c : word)
        {
            if (!node->next[c - 'a'])
            {
                node->next[c - 'a'] = new TrieNode();
            }
            node->next[c - 'a']->count++;
            node = node->next[c - 'a'];
        }
    }

    int prefixCount(string s)
    {
        auto node = &root;
        int ans = 0;
        for (char c : s)
        {
            ans += node->next[c - 'a']->count;
            node = node->next[c - 'a'];
        }
        return ans;
    }

    vector<int> sumPrefixScores(vector<string> &words)
    {
        int n = words.size();
        for (int i = 0; i < n; i++)
        {
            insert(words[i]);
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            ans[i] = prefixCount(words[i]);
        }
        return ans;
    }
};