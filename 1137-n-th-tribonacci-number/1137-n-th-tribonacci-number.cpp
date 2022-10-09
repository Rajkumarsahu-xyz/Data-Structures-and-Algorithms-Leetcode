class Solution {
public:
    
    int tribonacci(int n) 
    {
        if(n <= 1)
            return n;
        if(n == 2)
            return 1;
        
        int prev = 1, prev2 = 1, prev3 = 0, ans;
        for (int i = 3; i <= n; i++) 
        {
            ans = prev + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev;
            prev = ans;
        }
        
        return ans;
    }
};