//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n)
    {
        stack<long long> stk;
        vector<long long> ans;
        for(long long i=n-1; i>=0; i--)
        {
            if(stk.size() == 0)
            {
                ans.push_back(-1);
            }
                
            else if(stk.size()>0  &&  stk.top()>arr[i])
            {
                ans.push_back(stk.top());
            }
                
            else if(stk.size()>0  &&  stk.top()<=arr[i])
            {
                while(stk.size()>0  &&  stk.top()<=arr[i])
                {
                    stk.pop();
                }
                    
                if(stk.size() == 0)
                {
                    ans.push_back(-1);
                }
                else
                {
                    ans.push_back(stk.top());
                }
            }
               
            stk.push(arr[i]);
        }
            
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends