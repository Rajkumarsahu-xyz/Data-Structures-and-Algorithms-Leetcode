//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int n, int m) 
    {
        queue<pair<pair<int,int>, int>>q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 'X')
                    q.push({{i, j}, 0});
            }
        }
        
        vector<int> delrow = {0, 0, -1, 1};
        vector<int> delcol = {-1, 1, 0, 0};
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++)
            {
                int x1 = x + delrow[i];
                int y1 = y + delcol[i];
                
                if(x1>=0 && x1<n && y1>=0 && y1<m && grid[x1][y1] != 'X')
                {
                    if(grid[x1][y1] == 'Y')
                        return dis+1;
                        
                    else
                    {
                        grid[x1][y1] = 'X';
                        q.push({{x1, y1}, dis+1});
                    }
                }
            }
        }
        
        
        return -1;
        // {-1, 0 , 1 , 0 -1}
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends