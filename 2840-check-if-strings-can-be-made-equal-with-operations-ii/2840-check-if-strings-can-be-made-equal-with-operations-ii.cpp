class Solution {
public:
    bool checkStrings(string s1, string s2) 
    {
        int n = s1.length();
        
        vector<int> odds(26, 0), evens(26, 0);
        for(int i=0; i<n; i++)
        {
            if(i%2 == 0)
            {
                evens[s1[i]-'a']++;
                evens[s2[i]-'a']--;
            }
            else
            {
                odds[s1[i]-'a']++;
                odds[s2[i]-'a']--;
            }
        }
        
        for(int i=0; i<26; i++)
        {
            if(odds[i] > 0 || evens[i] > 0)
                return false;
        }
        
        return true;
    }
};