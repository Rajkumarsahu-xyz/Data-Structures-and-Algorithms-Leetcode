//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) 
    {
        sort(frogs, frogs+N);
        vector<int> visited(leaves+1, 0);
        for(int i=0; i<N; i++)
        {
            int k = frogs[i];
            if(k<=leaves && !visited[k])
            {
                for(int j=0; j<leaves+1; j+=k)
                {
                    visited[j] = 1;
                }
            }
        }
        
        int ctr = 0;
        for(int i=0; i<leaves+1; i++)
        {
            if(visited[i] == 0)
                ctr++;
        }
        
        return ctr;
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