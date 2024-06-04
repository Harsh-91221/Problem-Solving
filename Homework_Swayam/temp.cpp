class Solution
{
public:
    string clearStars(string s)
        priority_queue<char, vector<char>, greater<char>> pq;
        for (int i=0;i<.size();i++)
        {
            if (s[i]!= '*')
            {
                pq.push(s[i]);
            }
            else
            {
                if (!pq.empty())
                {
                    pq.pop(); 
                }
            }
        }
        string result = "";
        while (!pq.empty())
        {
            result += pq.top();
            pq.pop();
        }
        return result;
    }
};
