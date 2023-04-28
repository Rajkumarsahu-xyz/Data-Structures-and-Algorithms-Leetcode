//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &mat)
    {
        // vector<vector<int>> ans(n, vector<int> (m, 1e9));
        // vector<vector<int>> visited(n, vector<int> (m, 0));
        // queue<pair<int, int>> q;
        
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)
        //     {
        //         if(c[i][j] == 'W')
        //         {
        //             q.push({i, j});
        //             ans[i][j] = 0;
        //             visited[i][j] = 1;
        //         }
        //     }
        // }
        // vector<int> delmat = {-1, 0, 1, 0, -1};
        // while(!q.empty())
        // {
        //     int row = q.front().first;
        //     int col = q.front().second;
        //     // int dis = q.front().second();
        //     q.pop();
            
        //     for(int i=0; i<4; i++)
        //     {
        //         int nrow = row + delmat[i];
        //         int ncol = col + delmat[i+1];
        //         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && c[nrow][nrow]!='N')
        //         {
        //                 ans[nrow][ncol] = ans[row][col]+2;
        //                 q.push({nrow, ncol});
        //                 visited[nrow][ncol] = 1;
        //         }
        //     }
        // }
        
        
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)
        //     {
        //         if(c[i][j] == 'H') 
        //         {
        //             if(ans[i][j]==1e9)
        //                 ans[i][j] = -1;
        //             // else
        //             //     ans[i][j] *= 2;
        //         }
        //         else if(c[i][j] == 'N' || c[i][j] == '.')
        //         {
        //             ans[i][j] = 0;
        //         }
        //     }
        // }
        
        
        vector<vector<bool >> v(n,vector<bool>(m,false));
        vector<vector<int>> res(n,vector<int>(m,0));
        queue <pair<int,int>> q;
        int r[4] = {-1,0,1,0};
        int c[4] = {0,1,0,-1};
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 'W'){
                    v[i][j] = 1;
                    res[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int x = front.first;
            int y = front.second;
            for(int i = 0 ; i < 4 ; i++){
                int nr = x+r[i];
                int nc = y+c[i];
                if(nr < n && nc < m && nr >= 0 && nc >= 0 && !v[nr][nc] && mat[nr][nc] != 'N'){
                    res[nr][nc] = res[x][y]+2;
                    q.push({nr,nc});
                    v[nr][nc] = 1;
                }
            }
            
        }
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 'N' || mat[i][j] == '.'){
                    res[i][j] = 0;
                }
                else if(mat[i][j] == 'H'){
                    if(res[i][j] == 0){
                        res[i][j] = -1;
                    }
                }
            }
        }
        
        return res;
    }
        
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends