//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            if(n == 1)
                return a;
            
            vector<int> sum;
            for(int i=0; i<n-1; i++)
            {
                sum.push_back(a[i]+a[i+1]);
                // cout << sum[i] << endl; 
            }
            
            int i=0, j=0;
            for(; i<n-1 && j<n-1;)
            {
                if(sum[j]%2 == 0)
                    j++;
                else
                {
                    // cout << i << " " << j << endl;
                    sort(a.begin()+i, a.begin()+(j+1), greater<int>());
                    j++;
                    i = j;
                }
            }
            
            // cout << i << " " << j << endl;
            if(i!=n-1 && j==n-1)
                sort(a.begin()+i, a.end(), greater<int>());
                
            return a;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends