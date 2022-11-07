class Solution {
public:
    
    int reverse(int n)
    {
        int rev = 0;
        int a = n;
        while(a > 0)
        {
            int r = a%10;
            a /= 10;
            rev = rev*10 + r;
        }
        
        return rev;
    }
    
    int maximum69Number (int num) 
    {
        int rev = reverse(num);
        int ans = 0;
        int a = rev;
        int f = 0;
        while(a > 0)
        {
            int r = a%10;
            if(r == 6 && f==0)
            {
                r = 9;
                f = -1;
            }
            
            a /= 10;
            ans = ans*10 + r;   
        }
        
        return ans;
    }
};