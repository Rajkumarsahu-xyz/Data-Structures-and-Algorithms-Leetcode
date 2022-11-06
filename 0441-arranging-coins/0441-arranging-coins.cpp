class Solution {
public:
    int arrangeCoins(int n) 
    {
        int ctr = 0;
        for(int i=1; i<=n; i++)
        {
            ctr++;
            n -= i;
        }
        
        return ctr;
        
    }
};