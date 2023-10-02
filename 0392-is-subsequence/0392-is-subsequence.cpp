class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int ctr = 0;
        for(int i=0; i<t.length()  &&  ctr<s.length(); i++)
        {
            if(s[ctr] == t[i])
                ctr++;
        }
       
        if(ctr == s.length())
            return true;
        else
            return false;
    }
};