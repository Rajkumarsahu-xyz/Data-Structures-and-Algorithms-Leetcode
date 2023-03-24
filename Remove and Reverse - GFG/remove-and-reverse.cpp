//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string S) 
    {
        unordered_map<char, int> mp;
        for(int i=0; i<S.length(); i++)
        {
            mp[S[i]]++;
        }
        
        int n = S.length();
        vector<int> visited(n);
        int i=0, j=n-1;
        bool f = false;
        while(i<j)
        {
            while(i<j && mp[S[i]] <= 1)
            {
                // cout << mp[S[i]] << " " << S[i] << " " << i << endl; 
                // mp[S[i]]--;
                i++;
            }
            if(i<j && mp[S[i]] > 1)
            {
                mp[S[i]]--;
                visited[i] = 1;
                i++;
            }
            else if(i>=j || mp[S[i]] <= 1)
                break;
            
            f = !f;
            
            while(i<j && mp[S[j]] <= 1)
            {
                // cout << mp[S[i]] << " " << S[i] << " " << i << endl; 
                // mp[S[j]]--;
                j--;
            }
            if(i<j && mp[S[j]] > 1)
            {
                mp[S[j]]--;
                visited[j] = 1;
                j--;
            }
            else if(i>=j || mp[S[j]] <= 1)
                break;
                
            f = !f;
            // i++; j--;
        }
        
        // bool f = false;
        // if(mp[S[i]] > 1)
        //     mp[S[i]]--;
        // if(mp[S[j]] > 1)
        // {
        //     f = true;
        //     mp[S[j]]--;
        // }
        
        string p = "";
        for(int k=0; k<n; k++)
        {
            if(visited[k] == 0)
                p += S[k];
        }
        // cout << i << " " << j << endl;
        if(f == true)
        {
            reverse(p.begin(), p.end());
        }
        return p;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends