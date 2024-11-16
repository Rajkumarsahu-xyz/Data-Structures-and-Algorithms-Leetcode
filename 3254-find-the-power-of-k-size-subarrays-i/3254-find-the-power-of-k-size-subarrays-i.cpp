class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        vector<int> ans;
        bool flag = true;
        
        for(int i=0; i<(n-k+1); i++)
        {
            for(int j=0; j<k-1; j++)
            {
                if(nums[i+j] != nums[i+j+1]-1)
                {
                    flag = false;
                    break;
                }
            }
            
            if(flag == false)
            {
                flag = true;
                ans.push_back(-1);
            }
            else 
            {
                ans.push_back(nums[i+k-1]);
            }
        }
        
        return ans;
    }
};