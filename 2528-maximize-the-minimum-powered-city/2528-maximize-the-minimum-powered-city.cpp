class Solution {
public:
    bool isFeasible(long long  mid , vector<int>  stations, int r , int k)
    {
        long long sum=0;
        int n = stations.size();
        for(int i=0;i<r;i++)
        {
            sum += stations[i];
        }
        
        for(int i=0; i<n; i++)
        {
            if(i+r <= n-1)
            {
                sum += stations[i+r];
            }
            
            if(i-(r+1) >= 0)
            {
                sum -= stations[i-(r+1)];
            }
            
            if(sum < mid)
            {
                if(mid-sum > k)
                    return false;
                if(i+r <= n-1)
                    stations[i+r] += mid-sum;
                
                k -= mid-sum;
                sum = mid;
            }
        }
        
        return true;
    }

    
    long long maxPower(vector<int>& stations, int r, int k) 
    {
        long long i = 0, j = k, ans = 0;
        
        for(int i=0; i<stations.size(); i++)
            j += (long long) stations[i];
        
        while(i<=j)
        {
            long long  mid = i + (j-i)/2;
            if(isFeasible(mid,stations,r,k))
            {
				ans = mid;
                i = mid+1;
			}
            else
                j = mid-1;
        }
        
        return ans;
    }
};