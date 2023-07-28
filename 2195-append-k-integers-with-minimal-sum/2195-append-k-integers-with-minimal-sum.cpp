class Solution {
public:
    
    int i=0;
    int findKthPositive(vector<int>& arr, int k) 
    {
        int n = arr.size();
        
        int j = n-1;
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(arr[mid]-(mid+1) < k)
                i = mid+1;
            else
                j = mid-1;
        }
        
        if(i == 0)
            return k;
        
        int ans = arr[i-1] + (k - (arr[i-1]-i));
        return ans;
    }
    
    long long minimalKSum(vector<int>& nums, int k) 
    {
        
        unordered_set<int> s;
        for(int j=0; j<nums.size(); j++)
        {
            // cout << arr[j] << " ";
            s.insert(nums[j]);
        }
        vector<int> arr;
        for(auto x : s)
        {
            arr.push_back(x);
        }
        sort(arr.begin(), arr.end());
        int n = findKthPositive(arr, k);
        long long sum = (long long)((long long)(((long long)n)*((long long)((long long)n+1)))/2);
        
        if(i == 0)
            return sum;
        
        // cout << arr[i-1] << " " << n << " " << sum << endl;
        
        int j = 0;
        while(j<=i-1)
        {
            sum -= arr[j];
            j++;
        }
        
        return sum;
    }
};