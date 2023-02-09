//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    int maxInstance(string s)
    {
        int b = count(s.begin(), s.end(), 'b');
        int a = count(s.begin(), s.end(), 'a');
        int l = count(s.begin(), s.end(), 'l');
        int o = count(s.begin(), s.end(), 'o');
        int n = count(s.begin(), s.end(), 'n');
        return min({b, a, l / 2, o / 2, n});    
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends