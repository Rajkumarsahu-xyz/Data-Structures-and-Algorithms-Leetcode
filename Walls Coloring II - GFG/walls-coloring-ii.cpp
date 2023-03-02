//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minCost(vector<vector<int>> &costs) {
        int minFirst = -1;
        int minSecond = -1;
        for(int j = 0;j<costs[0].size();j++){
            if(minFirst==-1 || costs[0][j]<costs[0][minFirst]){
                minSecond = minFirst;
                minFirst = j;
            }
            else if(minSecond == -1 || costs[0][j]<costs[0][minSecond])
            minSecond = j;
        }
        for(int i = 1;i<costs.size();i++){
            int curFirst = -1,curSecond = -1;
            for(int j = 0;j<costs[0].size();j++){
                if(minFirst!=-1 && minFirst!=j)
                costs[i][j] += costs[i-1][minFirst];
                else if(minSecond!=-1 && minSecond!=j)
                costs[i][j] += costs[i-1][minSecond];
                else
                costs[i][j] = 2*1e8;
                if(curFirst == -1 || costs[i][j]<costs[i][curFirst]){
                curSecond = curFirst;
                curFirst = j;
                }
                else if(curSecond == -1 || costs[i][j]<costs[i][curSecond])
                curSecond = j;
            }
            // cout<<endl;
            minFirst = curFirst;
            minSecond = curSecond;
        }
        int ans = *min_element(costs.back().begin(),costs.back().end());
        return ans==2*1e8?-1:ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> costs(n, vector<int>(k));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) cin >> costs[i][j];
        }
        Solution obj;
        cout << obj.minCost(costs) << endl;
    }
}
// } Driver Code Ends