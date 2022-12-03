class Solution {
public:
    int minSteps(string s, string t) 
    {
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++)
        {
            mp[s[i]]++;
        }
        
        for(int i=0; i<t.length(); i++)
        {
            mp[t[i]]--;
        }
        
        int ctr = 0;
        for(auto x : mp)
        {
            ctr += abs(x.second);
        }
        
        return ctr;
    }
};