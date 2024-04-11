#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
    TrieNode *child[26];
    bool isEnd;

public:
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
        isEnd = false;
    }
    void insert(string word)
    {
        TrieNode *p = this;
        int n = word.length();
        for (int i = 0; i < n; i++)
        {
            if (p->child[word[i] - 'a'] == NULL)
            {
                p->child[word[i] - 'a'] = new TrieNode();
            }
            p = p->child[word[i] - 'a'];
        }
        p->isEnd = true;
    }
    void printsuggest(string word)
    {
        TrieNode *p = this;
        int n = word.length();
        string w = "";
        for (int i = 0; i < n; i++)
        {
            if (p->child[word[i] - 'a'] == NULL)
            {
                return;
            }
            w += word[i];
            p = p->child[word[i] - 'a'];
        }
        suggest(w, p);
    }
    void suggest(string w, TrieNode *p)
    {
        if (p->isEnd)
            cout << w << endl;
        for (int i = 0; i < 26; i++)
        {
            if (p->child[i] != NULL)
            {
                w += ('a' + i);
                suggest(w, p->child[i]);
                w.pop_back();
            }
        }
    }
};
int main()
{
    TrieNode *root = new TrieNode();
    root->insert("hello");
    root->insert("dog");
    root->insert("hell");
    root->insert("cat");
    root->insert("a");
    root->insert("hel");
    root->insert("help");
    root->insert("helps");
    root->insert("helping");
    root->printsuggest("hel");
    return 0;
}