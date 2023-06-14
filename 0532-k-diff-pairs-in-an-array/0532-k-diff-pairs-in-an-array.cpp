class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        int n = nums.size() ;
        sort(nums.begin(), nums.end());
        
        int i=0, j=1;
        int ctr = 0;
        while(j<n)
        {
            if(i==j || nums[j]-nums[i] < k)
                j++;
            
            else if(nums[j]-nums[i] == k)
            {
                ctr++;
                j++;
                while(j<n && nums[j]==nums[j-1])
                    j++;
            }
            
            else
            {
                i++;
                while(i<j && nums[i]==nums[i-1])
                    i++;
            }
        }
        
        return ctr;
    }
};