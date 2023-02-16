class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) 
    {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        int ans1=0, ans2=0;
        for(auto x : mp)
        {
            if(x.second%2 == 0)
                ans1 += (x.second/2);
            else
            {
                ans2++;
                ans1 += ((x.second-1)/2);
            }
        }
        
        return {ans1, ans2};
    }
};