class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int n = arr.size();
        
        int i=0, j=n-1;
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(arr[mid]-(mid+1) < k)
                i = mid+1;
            else
                j = mid-1;
        }
        
        // cout << arr[i-1] << " " << i << endl;
        if(i == 0)
            return k;
        
        int ans = arr[i-1] + (k - (arr[i-1]-i));
        return ans;
    }
};