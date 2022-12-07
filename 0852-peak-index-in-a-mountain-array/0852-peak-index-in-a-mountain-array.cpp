class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) 
    {
        int n = arr.size();
        int i=0, j=n-1;
        
        while(i<=j)
        {
            int mid = i + (j-i)/2;
            
            if(mid == 0)
                return (arr[mid] > arr[mid+1]) ? mid : mid+1;
            
            else if(mid == n-1)
                return (arr[mid] > arr[mid-1]) ? mid : mid-1;
            
            else if(arr[mid] > arr[mid+1]  &&  arr[mid] > arr[mid-1])
                return mid;
            
            else if(arr[mid] <= arr[mid-1])
                j = mid-1;
            
            else if(arr[mid] <= arr[mid+1])
                i = mid+1;
        }
        
        return -1;
    }
};