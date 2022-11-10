//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    vector<int> RopeCutting(int arr[], int n)
    {
        vector<int> ans;
        sort(arr, arr+n);
        int ctr = 1;
        int length = n;
        
        for(int i=0; i<n-1; i++)
        {
            if(arr[i] == arr[i+1])
            ctr++;
            
            else
            {
                length -= ctr;
                ans.push_back(length);
                ctr = 1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{   
    int T;
    cin>> T;
    while(T--)
    {
       	int n;
       	cin>>n;
       	int arr[n+1];
       	for(int i=0;i<n;i++)
       	   cin>>arr[i];
        
        vector<int> v;
        Solution ob;
        v = ob.RopeCutting(arr, n);
        for(int i : v){
            cout << i << " ";
        }
        cout << endl;
        
        
    }
  return 0;
}
// } Driver Code Ends