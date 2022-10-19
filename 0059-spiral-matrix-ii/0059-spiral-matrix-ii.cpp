class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> output(n, vector<int>(n));
        
        int i=0, j=0, k=1;
        int x=n, y=n, a=0, b=1;
        while(k <= n*n)
        {
            for(; j<y && k<=n*n; j++)
            {
                output[i][j] = k++;
            }
            i++; j--;
            
            for(; i<x && k<=n*n; i++)
            {
                output[i][j] = k++;
            }
            i--; j--;
        
            for(; j>=a && k<=n*n; j--)
            {
                output[i][j] = k++;
            }
            i--; j++;
        
            for(; i>=b && k<=n*n; i--)
            {
                output[i][j] = k++;
            }
            i++; j++;
            x--; y--; a++; b++;
        }
        
        return output;
    }
};