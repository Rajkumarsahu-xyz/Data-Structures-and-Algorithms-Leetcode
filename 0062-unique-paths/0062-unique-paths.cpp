class Solution {
public:
    
    int uniquePaths(int m, int n) 
    {
        vector<int> prev(n, 0);
        
        for(int i=0; i<m; i++)
        {
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++)
            {
                if(i==0  &&  j==0)
                {
                    curr[j] = 1;
                    continue;
                }
                
                if(i>0  &&  j>0)
                    curr[j] = curr[j-1] + prev[j];
                
                else if(i==0)
                    curr[j] = curr[j-1] + 0;
                else if(j==0)
                    curr[j] = 0 + prev[j];
                    
            }
            
            prev = curr;
        }
        
        return prev[n-1];
    }
};