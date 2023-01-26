//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>& board, int row, int col, vector<vector<int>>& visited, vector<pair<int, int>>& temp, int row0, int col0)
    {
        visited[row][col] = 1;
        temp.push_back({row-row0, col-col0});
        
        int n = board.size();
        int m = board[0].size();
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1}; 
        
        for(int i = 0;i<4;i++) 
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0  &&  nrow<n  &&  ncol>=0  &&  ncol<m  &&  !visited[nrow][ncol]  &&  board[nrow][ncol]==1) 
            {
                dfs(board, nrow, ncol, visited, temp, row0, col0);
            }
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) 
    {
       set<vector<pair<int, int>>> s;
       int n = grid.size(), m=grid[0].size();
       vector<vector<int>> visited(n, vector<int> (m, 0));
       for(int i=0; i<n; i++)
       {
           for(int j=0; j<m; j++)
           {
               if(!visited[i][j]  &&  grid[i][j]==1)
               {
                   vector<pair<int, int>> temp;
                   dfs(grid, i, j, visited, temp, i, j);
                   s.insert(temp);
               }
           }
       }
       
       return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends