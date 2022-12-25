class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) 
    {
        int ctr = 0, n = words.size();
        int mn = INT_MAX;
        for(int i=startIndex; i<=(startIndex-1+n); i++)
        {
            if(i >= n)
            {
                if(words[(i)%n]==target)
                    break;
            }
            else if(words[i] == target)
                break;
            ctr++;
        }
        if(ctr==n)
            mn = -1;
        else
            mn = min(mn, ctr);
        
        ctr=0;
        for(int i=startIndex; i>=(startIndex+1-n); i--)
        {
            if(i<0)
            {
                if(words[(i+n)]==target)
                {
                    break;
                }
            }
            else if(words[i]==target)
            {
                break;
            }
            ctr++;
        }
        
        if((ctr==n) && mn == -1)
            mn = -1;
        else
            mn = min(mn, ctr);
        return mn;
    }
};