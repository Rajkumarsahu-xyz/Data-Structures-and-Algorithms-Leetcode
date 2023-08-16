//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) 
    {
        //code here
        if(n==0)return 1;
        int mod=1e9+7;
        vector<long long>ans(n+1,0);
        
        ans[0]=1;
        ans[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                ans[i]=(ans[i] + (ans[j]*ans[i-j-1])%mod)%mod; //for factorial 
            }
        }
        
        
        return ans[n];
    }
};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends