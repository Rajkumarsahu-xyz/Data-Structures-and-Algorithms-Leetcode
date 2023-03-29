class Solution {
public:
    int maxsatis(vector<int>& satisfaction, int n, int t, vector<vector<int>> &dp)
    {
        if(n==0)
        {
            return max(0, satisfaction[n]*t);
        }
        
        if(dp[n][t] != -1)
            return dp[n][t];
        
        int nottake = 0, take = 0;
        if(n>0)
            nottake += max(nottake, maxsatis(satisfaction, n-1, t, dp));
        if(n>0)
            take += max(take, (satisfaction[n]*t) + maxsatis(satisfaction, n-1, t+1, dp));
        
        return dp[n][t] = max(nottake, take);
    }
    
    int maxSatisfaction(vector<int>& satisfaction)
    {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return maxsatis(satisfaction, n-1, 1, dp);
    }
};