//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int N, int M, int x, int y)
    {    
        vector<vector<int>> visited(N, vector<int>(M, 0));
        queue<pair<int, int>> q;
        q.push({x-1, y-1});
        visited[x-1][y-1] = 1;
        int ctr = 0;
        vector<int> rows = {-1, 0, 1, 0};
        vector<int> cols = {0, -1, 0, 1};
        while(!q.empty())
        {
            int len = q.size();
            bool p=0;
            for(int i=0; i<len; i++)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                for(int k=0; k<4; k++)
                {
                    if(r+rows[k]>=0 && r+rows[k]<=N-1 && c+cols[k]>=0 && c+cols[k]<=M-1 && visited[r+rows[k]][c+cols[k]]==0)
                    {
                        visited[r+rows[k]][c+cols[k]] = 1;
                        q.push({r+rows[k], c+cols[k]});
                    }
                }
                
            }
            
            if(!q.empty())
            {
                ctr++;
            }
        }
        
        return ctr;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends