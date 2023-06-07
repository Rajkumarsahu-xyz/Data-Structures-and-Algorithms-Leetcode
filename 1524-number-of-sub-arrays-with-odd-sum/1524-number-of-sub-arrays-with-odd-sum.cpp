class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        int n = arr.size();
        
        long long prefsum = 0;
        long long even = 1, odd = 0, ans = 0;
        
        for(int i=0; i<n; i++)
        {
            prefsum += arr[i];
            if(prefsum % 2 == 0)
            {
                ans += odd;
                even++;
            }
            else
            {
                ans += even;
                odd++;
            }
            
            ans %= (1000000007);
        }
        
        return ans;
    }
};