class Solution {
public:
    int climbStairs(int n) // Space Optimized
    {
        if (n <= 2) 
            return n;
        
        int prev = 2, prev2 = 1, res;
        for (int i = 3; i <= n; i++) 
        {
            res = prev + prev2;
            prev2 = prev;
            prev = res;
        }
        return res;
    }
};