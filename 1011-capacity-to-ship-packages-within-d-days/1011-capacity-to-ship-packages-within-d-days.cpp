class Solution {
public:
    
    int isfeasible(int mid, vector<int>& weights, int n, int days)
    {
        int ctr = 1;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += weights[i];
            if(sum > mid)
            {
                ctr++;
                sum = weights[i];
            }
            
            if(ctr > days)
                return false;
        }
        
        return true;
    }
    
    
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int n = weights.size();
        int mx = INT_MIN;
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            mx = max(mx, weights[i]);
            sum += weights[i];
        }
        
        int i = mx, j = sum;
        int ans = 0;
        while(i <= j)
        {
            int mid = i + (j-i)/2;
            if(isfeasible(mid, weights, n, days))
            {
                ans = mid;
                j = mid-1;
            }
            
            else
            {
                i = mid+1;
            }
        }
        
        return ans;
    }
};