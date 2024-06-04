class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < houses.size(); i++)
        {
            int mini = INT_MAX;
            for (int j = 0; j < heaters.size(); j++)
            {
                int ans = abs(houses[i] - heaters[j]);
                mini = min(mini, ans);
            }
            maxi = max(maxi, mini);
        }
        return maxi;
    }
};