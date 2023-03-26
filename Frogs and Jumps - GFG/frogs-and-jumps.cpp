//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    // int unvisitedLeaves(int N, int leaves, int frogs[]) 
    // {
    //     vector<int> v(leaves+1, 0);
    //     for(int i=0; i<N; i++)
    //     {
    //         int k = frogs[i];
    //         for(int j=0; j<leaves+1; j+=k)
    //         {
    //             if(j < leaves+1)
    //                 v[j] = 1;
    //         }
    //         int f = 0;
    //         for(int i=0; i<leaves+1; i++)
    //         {
    //             if(v[i] == 0)
    //                 f = 1;
    //         }
    //         if(f == 0)
    //             break;
    //     }
        
    //     int ctr = 0;
    //     for(int i=0; i<leaves+1; i++)
    //     {
    //         if(v[i] == 0)
    //             ctr++;
    //     }
        
    //     return ctr;
    // }
    
    
    
    
    int unvisitedLeaves(int n, int tl, int a[]) {
        // Code l
        
        vector<int> l(tl + 1, 0);
        int ul = 0;
        unordered_set<int> st;
        for(int i = 0; i < n; i++){
            int curr_ele = 0;
            
            // if remove this conditio then will not pass 5 test case. 
            // it tells, if any same number comes up again then, continue. 
            if(st.count(a[i]) == 0) st.insert(a[i]);
            else continue;
            while(curr_ele <= tl){
                curr_ele += a[i];
                
                if(curr_ele <= tl && l[curr_ele] == 0 ){
                    l[curr_ele] = 1;
                    ul++;
                }
            }
        }
        
        return tl - ul;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends