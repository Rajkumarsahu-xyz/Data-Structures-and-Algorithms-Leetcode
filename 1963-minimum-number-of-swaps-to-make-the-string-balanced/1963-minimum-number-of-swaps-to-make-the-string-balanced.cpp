class Solution {
public:
    int minSwaps(string s) 
    {
        int n = s.length();
        
        int ctr=0, swaps=0;
        
        for(int i=0; i<n; i++)
        {
            if(s[i] == '[')
                ctr++;
            else
            {
                if(ctr > 0)
                    ctr--;
                else
                    swaps++;
            }
        }
        return (swaps+1)/2;
    }
};