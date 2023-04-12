//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr)
    {
        sort(arr.begin(), arr.begin()+(n/2));
        
        int ctr = 0;
        for(int i=n/2; i<n; i++)
        {
            auto itr = lower_bound(arr.begin(), arr.begin()+(n/2), arr[i]*5);
            ctr += arr.begin()-itr + (n/2);
        }
        
        return ctr;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends