class Solution {
public:
    
    int rolltoTarget(int n, int i, int sum, int k, int target, vector<vector<int>>& dp)
    {
        if(i == n-1)
        {
            for(int j=1; j<=k; j++)
            {
                if(sum+j == target)
                    return 1;
            }
            
            return 0;
        }
        
        if(dp[i][sum] != -1)
            return dp[i][sum];
        
        long long int ways = 0;
        for(int j=1; j<=k; j++)
        {
            if(sum+j <= target)
                ways += fmod(rolltoTarget(n, i+1, sum+j, k, target, dp) , (1e9+7));
        }
        
        return dp[i][sum] = fmod(ways, (1e9+7));
    }
    
    int numRollsToTarget(int n, int k, int target) 
    {
        int i=0, sum=0;
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        return rolltoTarget(n, i, sum, k, target, dp);
    }
};