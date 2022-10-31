class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) 
    {
        unordered_map<string, int> mp;
        for (auto str : nums) 
        {
            if (str.size() < target.size()) 
                mp[str]++;
        }
        
        int ans = 0;
        for (auto x : mp) 
        {
            
            if (target.find(x.first) == 0) 
            {
                
                if (x.first+x.first == target) 
                    ans += x.second * (x.second-1);
                
                else 
                    ans += x.second * mp[target.substr((x.first).size())];
            }
        }
        
        return ans;
    }
};