class Solution {
public:
    
    int dp[31][1001] = {0};
    int numRollsToTarget(int n, int k, int target, int res = 0) 
    {
        if (n == 0 || target <= 0) 
            return n == target;
        
        if (dp[n][target]) 
            return dp[n][target] - 1;
        
        for (auto i = 1; i <= k; ++i)
            res = (res + numRollsToTarget(n - 1, k, target - i)) % 1000000007;
        
        dp[n][target] = res + 1;
        return res;
    }
    
};