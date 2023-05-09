class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int i=0, j=0, k=0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> output(m*n);
        
        int x=m, y=n, a=0, b=1;
        while(k < m*n)
        {
            for(; j<y && k<m*n; j++)
            {
                output[k++] = matrix[i][j];
            }
            i++; j--;
            
            for(; i<x && k<m*n; i++)
            {
                output[k++] = matrix[i][j];
            }
            i--; j--;
        
            for(; j>=a && k<m*n; j--)
            {
                output[k++] = matrix[i][j];
            }
            i--; j++;
        
            for(; i>=b && k<m*n; i--)
            {
                output[k++] = matrix[i][j];
            }
            i++; j++;
            x--; y--; a++; b++;
        }
        
        return output;
    }
};