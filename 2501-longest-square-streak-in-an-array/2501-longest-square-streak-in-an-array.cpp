class Solution {
public:
    int longestSquareStreak(vector<int>& nums) 
    {
        int ans = 0;
        unordered_set<int> s;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); i++) 
            s.insert(nums[i]);
        
        for(int i=0; i<nums.size(); i++)
        {   
            long long int x = nums[i];
            int ctr = 0;
            while(s.find(x) != s.end())
            {
                ctr++;
                s.erase(x);
                x = x*x;
            }
            ans = max(ans, ctr);
        }
        
        if(ans <= 1)
            return -1;
        else
            return ans;
    }
};