class Solution {
public:
    void bfs(vector<vector<int>>& board, int n, int m, queue<pair<int, int>>& q, vector<vector<int>>& visited)
    {
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1}; 
        while(!q.empty())
        {
            auto x = q.front();
            q.pop();
            int row = x.first;
            int col = x.second;
            for(int i=0; i<4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0  &&  nrow<n  &&  ncol>=0  &&  ncol<m  &&  !visited[nrow][ncol]  &&  board[nrow][ncol]==1) 
                {
                    visited[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    
    
    int numEnclaves(vector<vector<int>>& board) 
    {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        int ones=0;
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++)
	    {
            if(!visited[i][0]  &&  board[i][0]==1)
            {
                q.push({i, 0});
                visited[i][0] = 1;
            }
            
            if(!visited[i][m-1]  &&  board[i][m-1]==1)
            {
                q.push({i, m-1});
                visited[i][m-1] = 1;
            }
	    }
        
        
        
        for(int j=0; j<m; j++)
        {
            if(!visited[0][j]  &&  board[0][j]==1)
            {
                q.push({0, j});
                visited[0][j] = 1;
            }
            
            if(!visited[n-1][j]  &&  board[n-1][j]==1)
            {
                q.push({n-1, j});
                visited[n-1][j] = 1;
            }
        }
        
        bfs(board, n, m, q, visited);
        
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