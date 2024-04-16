class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int temp = 0;
            for (int j = i; j < arr.size(); j++)
            {
                temp ^= arr[j];
                if (temp == 0)
                {
                    ans += (j - i);
                }
            }
        }
        return ans;
    }
};