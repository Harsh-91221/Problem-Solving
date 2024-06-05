class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        // vector<int> ans;
        // for(int i=0;i<heights.size();i++)
        // {
        //     int count=0;
        //     int maxi=0;
        //     for(int j=i+1;j<heights.size();j++)
        //     {
        //         if(heights[j]>maxi)
        //         {
        //             count++;
        //             maxi=heights[j];
        //         }
        //         if(heights[j]>=heights[i])
        //         {
        //             break;
        //         }
        //     }
        //     ans.push_back(count);
        // }
        // return ans;
        stack<int> s;
        int n = heights.size();
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[i] > heights[s.top()])
            {
                ans[i]++;
                s.pop();
            }
            if (!s.empty())
            {
                ans[i]++;
            }
            s.push(i);
        }
        return ans;
    }
};