//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited = grid;
        
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
              if (grid[i][j] == 2) 
              {
                  q.push({{i, j}, 0}); 
                  visited[i][j] = 2;
              }
              else if(grid[i][j] == 1)
                  visited[i][j] = 1;
              
              else
                  visited[i][j] = 0;
            }
        }
        
        int time = 0;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, 1, 0, -1}; 

        while (!q.empty()) 
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            for (int i=0; i<4; i++) 
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol]!=2 && grid[nrow][ncol]==1) 
                {
                    q.push({{nrow, ncol}, t+1});
                    visited[nrow][ncol] = 2;
                }
            }
        }
        
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
              if (visited[i][j] == 1)
                  return -1;
            }
        }
        
        return time;
    }
    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends