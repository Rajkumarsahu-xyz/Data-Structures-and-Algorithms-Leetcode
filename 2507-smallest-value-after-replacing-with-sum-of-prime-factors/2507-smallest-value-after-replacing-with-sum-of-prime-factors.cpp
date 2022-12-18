class Solution {
public:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    
    void primefactors(int n, vector<int>& v)
    {
        int a = n;
        while (a % 2 == 0) 
        {
            v.push_back(2);
            a >>= 1;
        }
        while (a % 3 == 0) 
        {
            v.push_back(3);
            a=a/3;
        }
        for (int i = 5; i <= sqrt(n); i += 6) 
        {
            while (a % i == 0) 
            {
                v.push_back(i);
                a = a / i;
            }
            while (a % (i+2) == 0)
            {
                v.push_back(i+2);
                a = a / (i+2);
            }
        }
        
        if(a > 4)
            v.push_back(a);
    }
    
    int smallestValue(int n) 
    {
        while(!isPrime(n))
        {
            if(n == 4)
                return n;
            vector<int> v;
            primefactors(n, v);
            
            int sum  = 0;
            for(int i=0; i<v.size(); i++)
            {
                sum += v[i];
            }
            n = sum;
        }
        
        return n;
    }
};