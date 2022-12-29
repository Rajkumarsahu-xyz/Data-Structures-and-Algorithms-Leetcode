class Solution {
public:
    bool isfeasible(vector<int>& piles, int h, int bananas, int n)
    {
        int hours = 0, sum = 0;
        for(int i=0; i<n; i++)
        {
            hours += piles[i] / bananas;
            if(piles[i]%bananas != 0)
                hours++;
            
            if(hours > h)
                return false;
        }
        
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int min_k;
        int mx = INT_MIN, mn = INT_MAX, sum=0;
        int n = piles.size();
        
        for(int i=0; i<n; i++)
        {
            mn = min(mn, piles[i]);
            mx = max(mx, piles[i]);
        }
        
        if(n == h)
            return mx;
        
        int i=1, j=mx;
        while(i <= j)
        {
            int mid = (i+j)/2;
            if(isfeasible(piles, h, mid, n))
            {
                min_k = mid;
                j = mid-1;
            }
            
            else
            i = mid+1;
        }
        
        return min_k;
    }
};