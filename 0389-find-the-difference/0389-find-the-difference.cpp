class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        if(s == "")
            return t[0];
        
        int ans = 0;
        for(int i=0; i<s.size(); i++)
        {
            ans ^= (s[i] - 96);
            ans ^= (t[i] - 96);
        }
        ans ^= (t[t.size()-1] - 96);
        
        return char(ans + 96);
    }
};