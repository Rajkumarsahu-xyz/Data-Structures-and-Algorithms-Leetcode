//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		 int f(int i,int j, string &str,string &txt,vector<vector<int>> &dp){
	        if(i < 0 || j < 0)
	            return 0;
	        if(dp[i][j] != -1) return dp[i][j];
	        if(str[i] == txt[j] && i != j){
	            return dp[i][j] = 1 + f(i - 1,j - 1,str,txt,dp);
	        }
	        return dp[i][j] = max(f(i-1,j,str,txt,dp),f(i,j-1,str,txt,dp));
	    }
		int LongestRepeatingSubsequence(string &str){
		    int n = str.size();
		    string txt(str.begin(),str.end());
		    vector<vector<int>> dp(n,vector<int>(n,-1));
		    return f(n-1,n-1,str,txt,dp);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends