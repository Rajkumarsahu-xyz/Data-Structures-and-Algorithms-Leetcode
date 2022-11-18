class Solution {
public:
    int sqk(int n)
    {
        int a = n;
        int sum=0;
        while(a > 0)
        {
            int r = a%10;
            a /= 10;
            sum += r;
        }
        
        return sum;
    }
    
    int addDigits(int num) 
    {
        int a = num;
        while(a > 9)
        {
            a = sqk(a);
        }
        
        return a;
    }
};