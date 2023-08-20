//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int nums[], int n, int target) 
	{
	    int i=0, j=n-1;
        int first=0, last=-1;
        
        while(i <= j)
        {
            int mid = (i+j)/2;
            if(nums[mid] == target)
            {
                if(mid == 0  ||  nums[mid-1] != nums[mid])
                {
                    first = mid;
                    break;
                }
                else
                    j = mid-1;
            }
            
            else if(nums[mid] < target)
                i = mid+1;
            else
                j = mid-1;
        }
        
        i=0, j=n-1;
        while(i <= j)
        {
            int mid = (i+j)/2;
            if(nums[mid] == target)
            {
                if(mid == n-1  ||  nums[mid+1] != nums[mid])
                {
                    last = mid;
                    break;
                }
                else
                    i = mid+1;
            }
            
            else if(nums[mid] < target)
                i = mid+1;
            else
                j = mid-1;
        }
        
        return last-first+1;
	}
};



// } Driver Code Ends

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends