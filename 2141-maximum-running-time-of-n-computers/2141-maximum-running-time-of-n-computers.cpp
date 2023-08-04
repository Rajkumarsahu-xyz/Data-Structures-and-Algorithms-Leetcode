class Solution {
public:
    bool isfeasible(vector<int>& batteries, long long time, int n)
    {
        long long totTime = time*n;
        
        for(long long x : batteries)
        {
            totTime -= min(time, x);
        }
        
        return (totTime <= 0);
    }
    
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        long long i = 0, j = 0, sum = 0;
        for(int i = 0; i < batteries.size(); i++)
        {
            sum += batteries[i];
        }
        
        j = sum;
        long long ans = 0;
        while(i <= j)
        {
            
            long long mid = i + (j-i)/2;
            
            if(isfeasible(batteries, mid, n))
            {
                ans = mid;
                i = mid+1;
            }
            else
            {
                j = mid-1;
            }
        }
        
        return ans;
    }
};