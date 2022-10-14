class Solution {
public:
    
//    int paths(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
//    {
//         if(m==0  &&  n==0)
//             return 1;
        
//         if(m<0  ||  n<0)
//             return 0;
        
//         if(dp[m][n] != -1)
//             return dp[m][n];
        
//         int right=0;
//         int bottom=0;
        
//         if(m>0  &&  obstacleGrid[m-1][n] != 1)
//             right = paths(m-1, n, obstacleGrid, dp);
//         if(n>0  &&  obstacleGrid[m][n-1] != 1)
//             bottom = paths(m, n-1, obstacleGrid, dp);
        
//         return dp[m][n] = right+bottom;
//    }
        
    
    
        
//     int paths(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
//     {        
//         for(int i=0; i<m; i++)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 if(i==0  &&  j==0)
//                 {
//                     dp[i][j] = 1;
//                     continue;
//                 }
                
//                 int right=0;
//                 int down=0;
        
//                 if(i>0  &&  obstacleGrid[i-1][j] != 1)
//                     right = dp[i-1][j];
                
//                 if(j>0  &&  obstacleGrid[i][j-1] != 1)
//                     down = dp[i][j-1];
                
//                 dp[i][j] = right + down;
//             }
//         }
        
//         return dp[m-1][n-1];
//     }
    
    
    
    
    
    int paths(int m, int n, vector<vector<int>>& obstacleGrid, vector<int>& prev)
    {
        for(int i=0; i<m; i++)
        {
            vector<int> curr(n,0);
            for(int j=0; j<n; j++)
            {
                if(i==0  &&  j==0)
                {
                    curr[j] = 1;
                    continue;
                }
                
                int right=0;
                int down=0;
        
                if(i>0  &&  obstacleGrid[i-1][j] != 1)
                    right = prev[j];
                
                if(j>0  &&  obstacleGrid[i][j-1] != 1)
                    down = curr[j-1];
                
                curr[j] = right + down;
            }
            prev = curr;
        }
        
        return prev[n-1];
    }
    
    
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1) 
            return 0;
        vector<int> prev(n, 0);
        return paths(m, n, obstacleGrid, prev);
    }
};