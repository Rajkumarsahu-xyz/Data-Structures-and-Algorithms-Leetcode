class Solution {
public:
    bool isUgly(int n) 
    {
        for(int i=2; i<6 && n>0; i++)
        {
            while(n%i == 0 )
            {
                n /= i;
            }
        }
        
        if(n == 1)
            return true;
        else
            return false;
    }
};