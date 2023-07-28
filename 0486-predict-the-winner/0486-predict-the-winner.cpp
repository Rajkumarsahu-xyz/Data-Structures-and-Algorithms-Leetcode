class Solution {
public:
     
    int predict(vector<int>& nums, int i, int j)
    {
        if(i > j)
           return 0;
        if(i == j)
            return nums[i];
        
        int curr_score = max((nums[i] + min(predict(nums, i+2, j), predict(nums, i+1, j-1))) , (nums[j] + min(predict(nums, i, j-2), predict(nums, i+1, j-1))));
        
        return curr_score;
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
        
        int score1 = predict(nums, 0, n-1);
        int score2 = sum-score1;
        
        return score1>=score2;
    }
};