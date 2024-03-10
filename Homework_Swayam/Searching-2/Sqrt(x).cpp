class Solution
{
public:
    long long solve(long long x)
    {
        long long s = 0;
        long long e = x;
        long long ans = 0;
        long long key = x;
        while (s <= e)
        {
            long long mid = s + (e - s) / 2;
            if (mid * mid == key)
            {
                return mid;
            }
            if (mid * mid < key)
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }
    int mySqrt(int x)
    {
        return solve(x);
    }
};