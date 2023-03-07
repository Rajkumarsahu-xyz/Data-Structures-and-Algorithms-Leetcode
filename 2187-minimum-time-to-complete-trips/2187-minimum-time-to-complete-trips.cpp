#define ll long long int

class Solution {
public:
    
    bool feasible(ll mid, vector<int>& time, ll totalTrips)
    {
        ll trip = 0;
        for(int i=0; i<time.size(); i++)
        {
            trip += (mid/(ll)time[i]);
            if(trip >= totalTrips)
                return true;
        }
        
        return false;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        ll  mn=INT_MAX, mx=INT_MIN;
        ll ans = 0;
        sort(time.begin(), time.end());
        ll sum = 0;
        for(int i=0; i<time.size(); i++)
        {
            sum += time[i];
            mn = min(mn, (1LL)*time[i]);
            mx = max(mx, (1LL)*time[i]);
        }
        
        ll i = mn, j = (1LL*totalTrips*sum);
        // j = mx*(1LL)*totalTrips;
        while(i<=j)
        {
            ll mid = i + (j-i)/2;
            
            if(feasible(mid, time, totalTrips))
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