class Solution {
public:
     
    int predict(vector<int>& nums, int i, int j, vector<vector<int>> &dp)
    {
        if(i > j)
           return 0;
        if(i == j)
            return nums[i];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int curr_score = max((nums[i] + min(predict(nums, i+2, j, dp), predict(nums, i+1, j-1, dp))) , (nums[j] + min(predict(nums, i, j-2, dp), predict(nums, i+1, j-1, dp))));
        
        return dp[i][j] = curr_score;
    }
    
    bool PredictTheWinner(vector<int>& nums) 
    {
        int n = nums.size();
        
        if(n == 1)
            return true;
        
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
        }
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int score1 = predict(nums, 0, n-1, dp);
        int score2 = sum-score1;
        
        return score1>=score2;
    }
};