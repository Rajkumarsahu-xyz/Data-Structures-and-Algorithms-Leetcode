//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int S)
    {
        if(S>n*9 || (S==0 && n!=1))return "-1";
        
        string ans = "";
        int num = 9;
        for(int i=0;i<n; i++){
            if(num<=S ){
                ans += to_string(num);
            }
            else if(num>S){
                num = S;
                ans += to_string(num);
            }
            S-=num;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends