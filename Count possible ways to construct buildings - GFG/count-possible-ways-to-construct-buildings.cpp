//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define ll long long int
class Solution{
	public:
	int TotalWays(int N)
	{
	    vector<int> building(N+1), space(N+1);
	    building[0] = 1;
	    space[0] = 1;
	    
	    for(int i=1; i<N; i++)
	    {
	        building[i] = space[i-1];
	        space[i] = (space[i-1] + building[i-1]) % (1000000007);
	    }
	    
	    ll ans = (building[N-1] + space[N-1]) % (1000000007);
	    return (ans*ans) % (1000000007);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends