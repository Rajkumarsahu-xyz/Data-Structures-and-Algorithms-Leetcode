class Solution {
public:
    bool increasingTriplet(vector<int>& nums) 
    {
        if(nums.size() < 3)
            return false;
        int mn = nums[0];
        int mx = INT_MIN;
        vector<int> v;
        
        for(int i=nums.size()-1; i>=0; i--)
        {
            mx = max(mx, nums[i]);
            //cout << mx << endl;
            v.push_back(mx);
        }
        
        reverse(v.begin(), v.end());
        
        for(int i=1; i<nums.size()-1; i++)
        {
            if(mn < nums[i]  &&  nums[i] < v[i])
            {
                return true;
            }
            
            mn = min(mn, nums[i]);
        }
        
        return false;
        
    }
};