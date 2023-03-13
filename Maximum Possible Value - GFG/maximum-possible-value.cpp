//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    // long long maxPossibleValue(int N,vector<int> A, vector<int> B) 
    // {
    //     vector<pair<int, int>> pr;
    //     for(int i=0; i<N; i++)
    //     {
    //         pr.push_back({A[i], B[i]});
    //     }
        
    //     sort(pr.begin(), pr.end());
    //     for(int i=0; i<N; i++)
    //     {
    //         cout << pr[i].first << " " << pr[i].second << endl;
    //     }
    //     int ans = 0;
        
    //     int sqs = 0, recs = 0;
    //     int cur = 0;
    //     int f = -1;
    //     for(int i=N-1; i>=0; i--)
    //     {
    //         if(pr[i].second >= 4)
    //         {
    //             sqs = pr[i].second/4;
    //             ans += (pr[i].first*4*sqs);
                
    //             if(pr[i].second%4 >= 2)
    //             {
    //                 if(f == -1)
    //                 {
    //                     cur += pr[i].first*2;
    //                     f = 0;
    //                 }
    //                 else
    //                 {
    //                     ans += pr[i].first*2;
    //                     ans += cur;
    //                     cur = 0;
    //                     f = -1;
    //                 }
    //             }
    //         }
            
    //         else if(pr[i].second >= 2)
    //         {
    //             if(f == -1)
    //             {
    //                 cur += pr[i].first*2;
    //                 f = 0;
    //             }
    //             else
    //             {
    //                 ans += pr[i].first*2;
    //                 ans += cur;
    //                 cur = 0;
    //                 f = -1;
    //             }
    //         }
    //         cout << ans << endl;
    //     }
        
    //     return ans;
    // }
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) 

    {

        long long min=INT_MAX;

        long long ans=0;

        long long count=0;

        for(int i=0;i<N;i++)

        {

            if(A[i]<min && B[i]>1)

                min=A[i];

            

            int d = B[i]/2;

            ans+=d*2*A[i];

            count+=d*2;

        }

        if(count%4 !=0)

            ans-=min*2;

        return ans;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends