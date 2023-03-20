//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

#define pi pair<int, int>
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) 
    {
        int n = grid.size(), m = grid[0].size();
        if(source.first==destination.first  &&  source.second==destination.second)
        {
            return 0;
        }
        
        queue<pair<pair<int, int>, int>> q;
        q.push({{source.first, source.second}, 0});
        int destx = destination.first;
        int desty = destination.second;
        
        vector<int> del = {-1, 0, 1, 0, -1};
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++)
            {
                int x1 = x + del[i];
                int y1 = y + del[i+1];
                
                if(x1>=0 && x1<n && y1>=0 && y1<m && grid[x1][y1]==1)
                {
                    if(x1 ==  destx  &&  y1 == desty)
                        return dis+1;
                    grid[x1][y1] = 0;
                    q.push({{x1, y1}, dis+1});
                }
            }
        }
        
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends