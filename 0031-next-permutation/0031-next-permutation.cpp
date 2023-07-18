class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n = nums.size();
        int k = -1;
        for(int i=n-1; i>=1; i--)
        {
            if(nums[i-1]<nums[i])
            {
                k = i;
                break;
            }
        }
        
        if(k == -1)
        {
            reverse(nums.begin(), nums.end());
        }
        
        else
        {
            vector<int> temp(nums.begin() + k-1, nums.end());
            // for(int i=0; i<temp.size(); i++)
            // {
            //     cout << temp[i] << " ";
            // }
            // cout << endl;

            sort(temp.begin(), temp.end());
            int l = -1;
            int val = -1;
            for(int i=0; i<temp.size()-1; i++)
            {
                if(temp[i] == nums[k-1] && temp[i+1]>temp[i])
                {
                    val = temp[i+1];
                    l = i;
                    break;
                }
            }
            
            int t = nums[k-1];
            nums[k-1] = val;
            sort(nums.begin()+k, nums.end());
            nums[k+l] = t;
            
        }
    }
};