//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    public:
    
    int palin(string p, int l, int r)
    {
        int ctr = 0;
        int n = p.length();
        for(int i=0, j=n-1; i<j; i++, j--)
        {
            if(i>=l && j<=r)
            {
                if(p[i] != p[j])
                {
                    ctr = 1e9;
                    return ctr;
                }
            }
            
            else if(p[i] != p[j])
                ctr++;
        }
        
        return ctr;
    }
    
    int specialPalindrome(string s1, string s2)
    {
        int mx = INT_MAX;
        if(s2.length() > s1.length()/2)
            return -1;
        
        int n = s1.length(), m = s2.length();
        for(int i=0; i<s1.length()-s2.length()+1; i++)
        {
            string p = s1;
            int ctr = 0;
            for(int j=0; j<s2.length(); j++)
            {
                if(s1[i+j]!=s2[j])
                    ctr++;
                p[i+j] = s2[j];
            }
            
            ctr += palin(p, i, i+m-1);
            mx = min(mx, ctr);
        }
        
        
        
        return mx;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends