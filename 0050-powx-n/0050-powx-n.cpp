class Solution {
public:
    double myPow(double x, int n) 
    {
        if(n == 0)
            return 1;
        
        double ans = 1.0;
        
        long long int nn = abs(n);
        while(nn > 0)
        {
            if(nn%2 == 0)
            {
                x *= x;
                nn /= 2;
            }
            
            else
            {
                ans *= x;
                nn--;
            }
        }
        
        if(n < 0)
            return (double)(1.0) / (double)(ans);
        
        else
            return ans;
    }
};