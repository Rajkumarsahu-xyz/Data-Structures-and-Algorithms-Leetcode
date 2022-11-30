class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int, int> mp, occur;
        for(int i=0; i<arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        
        for(auto x : mp)
        {
            occur[x.second]++;
        }
        
        for(auto x : occur)
        {
            if(x.second > 1)
                return false;
        }
        
        return true;
    }
};