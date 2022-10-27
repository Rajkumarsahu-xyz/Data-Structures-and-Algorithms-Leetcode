class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        int sum = 0;
        for(int k=0; k<nums.size(); k++)
        {
            vector<int> v;
            for(int i=k+1, j=nums.size()-1; i<j; )
            {
                if(nums[k]+nums[i]+nums[j] == 0)
                {
                    v = {nums[k], nums[i], nums[j]};
                    ans.push_back(v);
                    
                    while (i < j && nums[i] == v[1]) i++;
                    while (i < j && nums[j] == v[2]) j--;
                }
                
                else if(nums[k]+nums[i]+nums[j] < 0)
                    i++;
                else
                    j--;
            }
            
            while (k+1 < nums.size() && nums[k+1] == nums[k]) 
                k++;
        }
        
        return ans;
    }
};