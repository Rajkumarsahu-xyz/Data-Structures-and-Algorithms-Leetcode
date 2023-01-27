//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	
// 	    void getCodes(string input, string out, int count, vector<string>& output)
//         {
//             if(input.size() == 0)
//             {
//                 output.push_back(out);
//                 //count++;
//                 return;
//             }
//             //if(dp[i] != -1) return dp[i];
//             char c1 = (input[0]-'0') + 'a' - 1;
//             if(input[0] == '0')
//             return;
            
//             getCodes(input.substr(1), out+c1, count, output);
            
//             if(input.size() > 1)
//             {
//                 int d = (input[0]-'0')*10 + (input[1]-'0');
//                 if(d > 26)
//                     return;
        
//                 char c2 = 'a' + d - 1;
//                 getCodes(input.substr(2), out+c2, count, output);
//             }
        
//             return;
//         }

// 		int CountWays(string str)
// 		{
// 		    if(str[0] == '0')
// 		    return 0;
		    
// 		    for(int i=0; i<str.length()-1; i++)
// 		    {
// 		        if(str[i]=='0' && str[i+1]=='0')
// 		        return 0;
// 		    }
		    
// 		    string out = "";
// 		    vector<string> output;
// 		    vector<int> dp(str.size(), -1);
		    
//             getCodes(str, out, 0, output);
//             return (output.size())%(1000000000);
// 		}


int mod = 1e9+7;
    int func(string &str,int n,vector<int>&dp){
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n]; 
        int cnt=0;
        if(str[n-1] >= '1') cnt = cnt + func(str,n-1,dp)%mod;
        if(str[n-2] =='1' || str[n-2] == '2' && str[n-1] <='6') cnt = (cnt + func(str,n-2,dp)%mod)%mod;
        
        return dp[n] = cnt%mod;
    }
	public:
		int CountWays(string str){
		    // Code here
		    int n=str.length();
		    if(str[0]=='0') return 0;
		    vector<int>dp(n+1,-1);
		    
		    return func(str,n,dp);
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
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends