class Solution {
public:
    
    int fallingPathSum(vector<vector<int>>& matrix, int n)
    {
        vector<int> prev(n, -1);
        for(int j=0; j<n; j++)
        {
            prev[j] = matrix[n-1][j];
        }
        
        for(int i=n-2; i>=0; i--)
        {
            vector<int> curr(n, -1);
            for(int j=n-1; j>=0; j--)
            {
                int downsum = matrix[i][j] + prev[j];
                
                int leftdgsum = matrix[i][j];
                if(j-1>=0)
                    leftdgsum += prev[j-1];
                else
                    leftdgsum += 1e9;
                
                int rightdgsum = matrix[i][j];
                if(j+1<=n-1)
                    rightdgsum += prev[j+1];
                else
                    rightdgsum += 1e9;
                
                curr[j] = min(downsum, min(rightdgsum, leftdgsum));
            }
            prev = curr;
        }
        
        int ans = INT_MAX;
    
        for(int j=0; j<n; j++)
        {
            ans = min(ans, prev[j]);
        }
        
        return ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        
        return fallingPathSum(matrix, n);
        
    }
};