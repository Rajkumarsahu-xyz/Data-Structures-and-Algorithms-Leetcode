//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
    unordered_map<long long, int> freq;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            long long x = numerator[i];
            long long y = denominator[i];
            long long g = __gcd(x, y);
            x /= g;
            y /= g;
            long long temp_x = y - x;
            long long temp_y = y;

            if (freq.find({temp_x * 1000000007LL + temp_y}) != freq.end())
            {
                ans += freq[{temp_x * 1000000007LL + temp_y}];
            }

            freq[{x * 1000000007LL + y}]++;
        }

        return ans;
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends