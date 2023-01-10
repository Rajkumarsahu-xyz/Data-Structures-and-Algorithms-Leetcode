//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(vector<vector<char>>& board, int row, int col, vector<vector<int>>& visited)
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

            if(nrow>=0  &&  nrow<n  &&  ncol>=0  &&  ncol<m  &&  !visited[nrow][ncol]  &&  board[nrow][ncol]=='O') 
            {
                dfs(board, nrow, ncol, visited);
            }
        }
    }
    
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> board)
    {
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i=0; i<n; i++)
	    {
            if(!visited[i][0]  &&  board[i][0]=='O')
            {
                dfs(board, i, 0, visited);
            }
            
            if(!visited[i][m-1]  &&  board[i][m-1]=='O')
            {
                dfs(board, i, m-1, visited);
            }
	    }
        
        for(int j=0; j<m; j++)
        {
            if(!visited[0][j]  &&  board[0][j]=='O')
            {
                dfs(board, 0, j, visited);
            }
            
            if(!visited[n-1][j]  &&  board[n-1][j]=='O')
            {
                dfs(board, n-1, j, visited);
            }
        }
        
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!visited[i][j]  &&  board[i][j]=='O')
                {
                    board[i][j] = 'X';
                }
            }
        }
        
        return board;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends