class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int> (n, -1));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                ans[i][j] = matrix[n-1-j][i];
            }
        }
        
        matrix = ans;
    }
};