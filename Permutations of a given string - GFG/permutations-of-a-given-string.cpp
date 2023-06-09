//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		void solve(string &s, vector<string>&ans, int index,unordered_map<string,int>&mp)
		{
            if(index >= s.size()){
                if(mp.find(s) == mp.end()){
                    ans.push_back(s);
                    mp[s]++;
                }
                return;
            }
            for(int i = index ;i<s.size();i++){
                swap(s[index],s[i]);
                solve(s,ans,index+1,mp);
                swap(s[index],s[i]);
            }
        }
        
        vector<string>find_permutation(string S)
        {
            vector<string>ans;
            unordered_map<string,int>mp;
            solve(S,ans,0,mp);
            sort(ans.begin(),ans.end());
            return ans;
        }
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends