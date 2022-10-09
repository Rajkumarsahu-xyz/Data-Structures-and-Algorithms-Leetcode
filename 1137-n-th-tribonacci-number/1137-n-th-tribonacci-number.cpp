class Solution {
public:
    
    int tribo(int n, vector<int>& dp)
    {
        if(n <= 1)
            return n;
        if(n == 2)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = tribo(n-1, dp) + tribo(n-2, dp) + tribo(n-3, dp);
    }
    
    int tribonacci(int n) 
    {
        if(n <= 1)
            return n;
        if(n == 2)
            return 1;
        
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        return tribo(n, dp);
    }
};