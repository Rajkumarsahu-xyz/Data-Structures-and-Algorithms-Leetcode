class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        if(matrix.size() == 1  ||  matrix[0].size() == 1)
            return true;

        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(i>0 && j>0 && matrix[i][j] != matrix[i-1][j-1])
                    return false;
            }
        }
        
        return true;
    }
};