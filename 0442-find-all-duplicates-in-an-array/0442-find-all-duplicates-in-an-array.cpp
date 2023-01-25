class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> ans;
        int ctr = 0;
        for(int i=0; i<n; i++) 
        {
            int m = abs(nums[i]) - 1;
            if(nums[m] > 0)
                nums[m] = -nums[m];
            else
            {
                nums[m] = (nums[m]);
                ans.push_back(m+1);
            }
            // nums[m] = nums[m]>0 ? -nums[m] : nums[m];
        }
        //cout << ctr <<endl;
//         for(int i=0; i<n; i++) 
//         {
//             //cout << nums[i] << endl;
//             if(nums[i] > 0)
//                 nums.push_back(nums[i]);
//         }
        
//         nums.erase(nums.begin(), nums.begin()+n);
//         // cout << nums.size()-ctr << endl;
//         // for(int i=0; i<(nums.size()-(ctr)); i++)
//         // {
//         //     nums.pop_back();
//         // }
        
        return ans;
    }
};