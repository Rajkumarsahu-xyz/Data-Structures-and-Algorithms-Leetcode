class Solution {
public:
    bool buddyStrings(string s, string goal) 
    {
        if(s.length() != goal.length())
            return false;
        
        if(s == goal)
        {
            vector<int> chars(26);
            for(int i=0; i<s.length(); i++)
            {
                chars[s[i]-'a']++;
                
                if(chars[s[i]-'a'] == 2)
                    return true;
            }

            return false;
        }
        
        vector<int> diff;
        int ctr=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] != goal[i])
            {
                ctr++;
                diff.push_back(i);
            }
            
            if(ctr > 2)
                return false;
        }
        
        if((ctr == 2) && (s[diff[0]] == goal[diff[1]]) && (s[diff[1]] == goal[diff[0]]))
            return true;
        else
            return false;
    }
};