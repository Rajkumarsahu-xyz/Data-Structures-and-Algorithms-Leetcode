class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> pt;
        
        for(auto i=0; i<numRows; i++)
        {
            pt.push_back(vector<int>(i+1, 1));
            
            for(auto j=1; j<i; j++)
            {
                pt[i][j] = pt[i-1][j-1] + pt[i-1][j];
            }
        }
        return pt;
        
  
    }
};