//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int lcs(int n, int m, string s1, string s2)
    {
        vector<int> prev(m+1, 0), cur(m+1,0);
        for(int i =1; i<=n ; i++)
        {
            for(int j =1; j<=m; j++)
            {
                if(s1[i-1] == s2[j-1]) 
                    cur[j] = 1+ prev[j-1];
                 
                else 
                    cur[j] =  max(prev[j] , cur[j-1]);
            }
            prev = cur;
        }
        
        return prev[m];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends