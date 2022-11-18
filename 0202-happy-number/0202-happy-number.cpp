class Solution {
public:
    
    int sqk(int n)
    {
        int a = n;
        int sq=0;
        while(a > 0)
        {
            int r = a%10;
            a /= 10;
            sq += (r*r);
        }
        
        return sq;
    }
    
    bool isHappy(int n)
    {
        int slow = sqk(n);
        int fast = sqk(sqk(n));
        
        while(slow != fast)
        {
            slow = sqk(slow);
            fast = sqk(sqk(fast));
        }
        
        return fast == 1;
    }
};