//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        // Code here
        priority_queue<vector<int>> pq;
        for(auto& x : intervals) pq.push({x[1], x[0], 1});
        if(k == 1) return pq.top()[0];
        while(pq.size() > 1) {
            auto it1 = pq.top();
            pq.pop();
            auto it2 = pq.top();
            // Disjoint
            if(it2[0] < it1[1]) continue;
            // Overlapping
            if(it1[2]+it2[2] >= k) return it2[0];
            pq.pop();
            int minStart = min(it1[1], it2[1]), maxStart = max(it1[1], it2[1]);
            pq.push({it2[0], maxStart, it1[2]+it2[2]});
            if(minStart != maxStart) {
                int f = it1[1] == minStart ? it1[2] : it2[2];
                pq.push({maxStart-1, minStart, f});
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends