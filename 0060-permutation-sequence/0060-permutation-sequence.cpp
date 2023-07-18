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
            for(int i=n-1; i>=0; i--)
            {
                if(nums[i] > nums[k-1])
                {
                    swap(nums[i], nums[k-1]);
                    break;
                }
            }
            
            reverse(nums.begin()+k, nums.end());
        }
    }
    
    string getPermutation(int n, int k) 
    {
        vector<int> nums(n);
        for(int i=0; i<n; i++)
        {
            nums[i] = i+1;
        }
        
        while(k>1)
        {
            nextPermutation(nums);
            --k;
        }
        
        string ans = "";
        for(int i=0; i<n; i++)
        {
            // cout << nums[i] << " ";
            ans += ('0' + nums[i]);
        }
        // cout << endl;
        return ans;
    }
};