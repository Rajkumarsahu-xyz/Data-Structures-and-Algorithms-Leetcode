//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>& board, int row, int col, vector<vector<int>>& visited)
    {
        visited[row][col] = 1;
        
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
                dfs(board, nrow, ncol, visited);
            }
        }
    }
    
  
    int numberOfEnclaves(vector<vector<int>> &board) 
    {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        int ones=0;
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)
        //     {
        //         if(board[i][j] == 1)
        //             ones++;
        //     }
        // }
        
        for(int i=0; i<n; i++)
	    {
            if(!visited[i][0]  &&  board[i][0]==1)
            {
                dfs(board, i, 0, visited);
            }
            
            if(!visited[i][m-1]  &&  board[i][m-1]==1)
            {
                dfs(board, i, m-1, visited);
            }
	    }
        
        
        
        for(int j=0; j<m; j++)
        {
            if(!visited[0][j]  &&  board[0][j]==1)
            {
                dfs(board, 0, j, visited);
            }
            
            if(!visited[n-1][j]  &&  board[n-1][j]==1)
            {
                dfs(board, n-1, j, visited);
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j]  &&  board[i][j] == 1)
                    ones++;
            }
        }
        
        return ones;
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends