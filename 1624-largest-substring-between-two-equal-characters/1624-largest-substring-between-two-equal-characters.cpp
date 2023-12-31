class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) 
    {
        int n = s.length();
        unordered_map<char, int> mp, mp1;
        
        for(int i=0; i<n; i++) 
        {
            if(mp.find(s[i]) != mp.end()) 
            {
                // cout << "raj" << endl;
                mp1[s[i]] = i;
            }
            else 
            {
                mp[s[i]] = i;
            }
        }
        
        int mx = -1;
        for(auto x : mp) 
        {
            if(mp1.find(x.first) != mp1.end())
            {
                mx = max(mx, (mp1[x.first] - mp[x.first] - 1));
            }
        }
        
        return mx;
        
    }
};