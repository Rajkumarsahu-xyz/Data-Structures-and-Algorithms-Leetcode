class Solution {
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int i = 0, j = n-1;
        
        while (i<=j)
        {
            int mid = i + (j-i)/2;
            
            if (arr[mid]-(mid+1) < k)
                i = mid+1;
            else
                j = mid-1;
        }
        return i+k;
    }
};