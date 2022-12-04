class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) 
    {
        vector<long long> pref;
        int n = nums.size();
        long long sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += nums[i];
            pref.push_back(sum);
        }
        
        int index = 0;
        int mn = INT_MAX;
        for(int i=0; i<n; i++)
        {
            long long a = (pref[i]/(i+1));  
            long long b;
            if(n-i-1 > 0)
                b = ((sum-pref[i])/(n-i-1));
            else
                b = 0;
            
            int x = abs(a - b); 
            if(x < mn)
            {
                mn = x;
                index = i;
            }
        }
        
        return index;
    }
};