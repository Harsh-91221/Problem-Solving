class Trie
{
public:
    bool endOfWord = false;
    Trie *children[26];
};

class Solution
{
public:
    Trie *head = new Trie();
    Trie *curr = new Trie();
    vector<string> words;
    string result = "";

    void insertWord(string s)
    {
        curr = head;
        for (int i = 0; i < s.size(); i++)
        {
            if (curr->children[s[i] - 'a'] == NULL)
            {
                curr->children[s[i] - 'a'] = new Trie();
            }
            curr = curr->children[s[i] - 'a'];
        }
        curr->endOfWord = true;
    }

    void splitSentence(string s)
    {
        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ' && temp != "")
            {
                words.push_back(temp);
                temp = "";
            }
            else
                temp.push_back(s[i]);
        }
        if (temp != "")
            words.push_back(temp);
    }

    void helper(string word)
    {
        curr = head;
        string temp = "";
        for (int i = 0; i < word.size(); i++)
        {
            if (curr->endOfWord)
                break;
            if (curr == NULL || curr->children[word[i] - 'a'] == NULL)
            {
                temp = word;
                break;
            }
            temp.push_back(word[i]);
            curr = curr->children[word[i] - 'a'];
        }
        result.push_back(temp);
    }

    string replaceWords(vector<string> &dictionary, string sentence)
    {
        for (int i = 0; i < dictionary.size(); i++)
        {
            insertWord(dictionary[i]);
        }
        splitSentence(sentence);
        for (int i = 0; i < words.size(); i++)
        {
            helper(words[i]);
            if (i != words.size() - 1)
                result.push_back(' ');
        }
        return result;
    }
};