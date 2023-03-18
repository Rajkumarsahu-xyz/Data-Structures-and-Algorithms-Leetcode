//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    
    // int countSubarrays(vector<int>& nums, int k) 
    // long long countSubarray(int n, vector<int> nums, int k) 
    // {
    //     int indk = 0;
    //     for(int i=0; i<n; i++)
    //     {
    //         if(nums[i] == k) break;
            
    //         indk++;
    //     }
        
    //     unordered_map<int, int> mp;
    //     mp[0]++;
    //     int diff = 0;
    //     for(int i=indk+1; i<nums.size(); i++)
    //     {
    //         if(nums[i] > k)
    //             diff++;
    //         else 
    //             diff--;
            
    //         mp[diff]++;
    //     }
        
    //     int ctr = mp[0] + mp[1];
        
    //     diff = 0;
    //     for(int i=indk-1; i>=0; i--)
    //     {
    //         if(nums[i] > k)
    //             diff++;
    //         else
    //             diff--;
            
    //         ctr += (mp[0-diff] + mp[1-diff]);
    //     }
        
    //     return ctr;
    // }
  
    long long helper( int n, const vector< int >& a, int m ) 
    {
        vector< int > v( 2 * n + 1 ); v[ n ]++;
        long long x{}, t{}, j{ n };
        for ( int i{}; i < n; ++i, ++v[ j ] )
            x += t += a[ i ] >= m ? v[ j++ ] : -v[ --j ];
        return x;
    }
    
    long long countSubarray( int N, vector< int > A, int M ) 
    {
        return helper( N, A, M ) - helper( N, A, ++M );
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin>>N>>M;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution obj;
        auto ans = obj.countSubarray(N,A,M);
        cout<<ans<<endl;
    }
}  
// } Driver Code Ends