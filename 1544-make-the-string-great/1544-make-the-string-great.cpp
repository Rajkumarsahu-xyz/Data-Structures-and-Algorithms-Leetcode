class Solution {
public:
    string makeGood(string s) 
    {     
        string str;
        
        for(int i = 0 ; i < s.length() ; i++)
        {
            str.push_back(s[i]);
            
            while(str.length() > 0  &&  abs(s[i+1]-str.back()) == 32)
            {
                str.pop_back();
                i++;
            }
        }
        
        return str;
    }
};