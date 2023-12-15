class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
        unordered_map<string, int> mp;
        int n = paths.size();
        for(int i=0; i<n; i++ )
        {
            mp[paths[i][1]]++;
        }
        
        for(int i=0; i<n; i++ )
        {
            mp[paths[i][0]]--;
        }
        
        for(auto x : mp) 
        {
            if(x.second >= 1) 
                return x.first;
        }
        
        return "1";
    }
};