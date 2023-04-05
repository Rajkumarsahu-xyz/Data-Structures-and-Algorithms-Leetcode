class Solution {
public:
    bool isfeasible(long long tar, vector<long long> a, long long n)
    {
        if(a[0] > tar)
            return false;
        
        for(int i=1; i<n; i++)
        {
            if(a[i-1] <= tar)
            {
                long long k = tar-a[i-1];
                a[i-1] += k;
                a[i] -= k;
                if(a[i] > tar)
                    return false;
            }
        }
        
        return true;
    }
    
    int minimizeArrayValue(vector<int>& nums) 
    {
        int n = nums.size();
        
        vector<long long> v(n);
        for(int i=0; i<n; i++)
            v[i] = nums[i];
        
        long long mn=LLONG_MAX, mx=LLONG_MIN;
        for(int i=0; i<n; i++)
        {
            mn = min(mn, v[i]);
            mx = max(mx, v[i]);
        }
        
        long long i=v[0], j=mx;
        long long ans = mx;
        while(i<=j)
        {
            long long mid = i + (j-i)/2;
            if(isfeasible(mid, v, n))
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