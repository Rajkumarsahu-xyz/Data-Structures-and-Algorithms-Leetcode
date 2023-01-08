//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int arr[], int N) 
    {
        vector<int>v;
        v.push_back(arr[0]);
        
        for(int i=1;i<N;i++)
        {
            auto index = lower_bound(v.begin(),v.end(),arr[i]);
            
            if(index == v.end())
            v.push_back(arr[i]);
            else
            v[index-v.begin()] = arr[i];
        }
        
        return N-v.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends