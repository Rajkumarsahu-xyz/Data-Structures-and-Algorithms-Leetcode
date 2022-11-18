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
        if(n == 1)
            return true;
        vector<int> sqnum;
        sqnum.push_back(n);
        
        int a = n;
        while(a > 1)
        {
            a = sqk(a);
            cout << a << " " ;
            if(a == 1)
                return true;
            else if(find(sqnum.begin(), sqnum.end(), a) != sqnum.end())
                return false;
            else
                sqnum.push_back(a);
        }
        
        return true;
    }
};