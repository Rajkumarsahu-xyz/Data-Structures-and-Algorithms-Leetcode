class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n=grid[0].size();
        vector<int> onesRow, onesCol, zerosRow, zerosCol;
        
        vector<vector<int>> diff(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++) 
        {
            int ctr0 = 0, ctr1 = 0;
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                    ctr1++;
                else
                    ctr0++;
            }
            onesRow.push_back(ctr1);
            zerosRow.push_back(ctr0);
        }
        
        for(int i=0; i<n; i++) 
        {
            int ctr0 = 0, ctr1 = 0;
            for(int j=0; j<m; j++)
            {
                if(grid[j][i] == 1)
                    ctr1++;
                else
                    ctr0++;
            }
            onesCol.push_back(ctr1);
            zerosCol.push_back(ctr0);
        }
        
        for(int i=0; i<m; i++) 
        {
            for(int j=0; j<n; j++)
            {
                // cout << onesRow[i] << " " << onesCol[j] << " " << zerosRow[i] << " " << zerosCol[j] << endl;
                diff[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }
        
        return diff;
    }
};