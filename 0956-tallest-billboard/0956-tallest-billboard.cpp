class Solution {
public:
    int billboard(vector<int>& rods, int i, int d, int n, vector<vector<int>>& dp, int sum) 
    {

        if (i == n)
        {
            if (d == 0)
                return 0;
            return -1e9;
        }
        
        if(dp[i][d+sum] != -1)
            return dp[i][d+sum];
        
        int opt1 = billboard(rods, i+1 , d, n, dp, sum);
        int opt2 = rods[i] + billboard(rods, i+1 , d+rods[i], n, dp, sum);
        int opt3 = billboard(rods, i+1 , d-rods[i], n, dp, sum);

        return dp[i][d+sum] = max({opt1, opt2, opt3});
    }
    
    int tallestBillboard(vector<int>& rods) 
    {
        int n = rods.size();
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += rods[i];
        }
        // sum = 5000;
        
        vector<vector<int>> dp(n+1, vector<int>((2*sum)+1, -1));
        return billboard(rods, 0, 0, n, dp, sum);
    }
};