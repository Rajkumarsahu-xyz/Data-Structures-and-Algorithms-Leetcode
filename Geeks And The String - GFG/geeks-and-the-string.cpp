//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // code here
        stack<char>st;
        for(char x:s){
            if(st.empty()==false&&st.top()==x)st.pop();
            else st.push(x);
        }
        
        string ans;
        while(st.empty()==false){
            ans.push_back(st.top());st.pop();
        };
        reverse(ans.begin(),ans.end());
        if(ans.size()==0)return "-1";
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends