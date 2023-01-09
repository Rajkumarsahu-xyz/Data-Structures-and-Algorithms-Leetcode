//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int N, vector<int> A) 
    {
        for(int i=N-1; i>=0; i--)
        {
            A[i] += 1;
            if(A[i] > 9)
            {
                A[i] = 0;
                A[i-1] += 1;
            }
            
            else 
            return i+1;
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> A(N);

        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.solve(N, A) << "\n";
    }
    return 0;
}
    
// } Driver Code Ends