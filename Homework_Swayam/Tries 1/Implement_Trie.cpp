class Trie
{
public:
    struct TrieNode
    {
        bool isEndofWord;
        TrieNode *children[26];
    };
    TrieNode *getNode()
    {
        TrieNode *newNode = new TrieNode();
        newNode->isEndofWord = false;
        for (int i = 0; i < 26; i++)
        {
            newNode->children[i] = NULL;
        }
        return newNode;
    }
    TrieNode *root;
    Trie()
    {
        root = getNode();
    }

    void insert(string word)
    {
        TrieNode *crawler = root;
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL)
            {
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEndofWord = true;
    }

    bool search(string word)
    {
        TrieNode *crawler = root;
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL)
            {
                return false;
            }
            crawler = crawler->children[idx];
        }
        if (crawler != NULL && crawler->isEndofWord == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool startsWith(string prefix)
    {
        TrieNode *crawler = root;
        int i = 0;
        for (i = 0; i < prefix.length(); i++)
        {
            char ch = prefix[i];
            int idx = ch - 'a';
            if (crawler->children[idx] == NULL)
            {
                return false;
            }
            crawler = crawler->children[idx];
        }
        if (i == prefix.length())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */