class Solution {
public:
    int longestPalindrome(string s) 
    {
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++)
        {
            mp[s[i]]++;
        }
        
        int ctr = 0;
        int mx = 0;
        for(auto x: mp)
        {
            //cout << x.second << " " << ctr << endl;
            if(x.second%2 != 0)
            {
                mx = max(mx, x.second);
                ctr += x.second-1;
            }
            
            else
                ctr += x.second;
            //cout << mx << endl;
        }
        
        if(mx != 0)
            return ctr+1;
        
        else
            return ctr;
    }
};