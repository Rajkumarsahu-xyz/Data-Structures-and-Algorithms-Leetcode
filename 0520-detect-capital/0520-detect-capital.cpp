class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        int ctr = 0;
        for(int i=0; i<word.length(); i++)
        {
            if(word[i]>=65 && word[i]<=90)
                ctr++;
        }
        
        if(ctr==1  &&  (word[0]>=65 && word[0]<=90))
            return true;
        else if(ctr==word.length() || ctr==0)
            return true;
        else
            return false;
    }
};