class Solution {
public:
    int arrangeCoins(int n) 
    {
        int i=0, j=n;
        while(i <= j)
        {
            long long mid = i + (j-i)/2;
            long long k = (mid*(mid+1))/2;
            
            if(k == n)
                return mid;
            else if(k < n)
                i = mid+1;
            else
                j = mid-1;  
        }
        
        return j;
    }
};