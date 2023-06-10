class Solution {
public:
    int countElements(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n == 1 || n == 2)
            return 0;
        
        int ctr = 0;
        for(int i=0; i<n-1; i++)
        {
            if(nums[i] == nums[i+1])
                ctr++;
            else
                break;
        }
        
        // cout << ctr << endl;
        if(ctr == n-1 || ctr == n-2)
            return 0;
        
        for(int i=n-1; i>0; i--)
        {
            if(nums[i] == nums[i-1])
                ctr++;
            else
                break;
        }
        
        // cout << n << endl;
        // if(ctr == (n*2) || ctr == ())
        //     ctr = n;
        return n-ctr-2;
    }
};