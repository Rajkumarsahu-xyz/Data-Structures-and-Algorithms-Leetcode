//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int N,int K,vector<int> &A)
    {
        if(N == 1) 
            return 0;
        
        vector<int> pref(N), suff(N);
        pref[0] = A[0], suff[N-1] = A[N-1];
        for(int i=1; i<N; i++)
        {
            int mx = max(pref[i-1], A[i]);
            pref[i] = mx;
        }
        
        for(int i=N-2; i>=0; i--)
        {
            // cout << suff[i+1] << " " << A[i] << endl;
            int mn = min(suff[i+1], A[i]);
            suff[i] = mn;
        }
        
        int ctr = 0;
        // for(int i=0; i<N; i++)
        // {
        //     cout << pref[i] << " ";
        // }
        // cout << endl;
        // for(int i=0; i<N; i++)
        // {
        //     cout << suff[i] << " ";
        // }
        // cout << endl;
        
        for(int i=0; i<N-1; i++)
        {
            if(pref[i]+suff[i+1] >= K)
                ctr++;
        }
        
        return ctr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends