// class Solution {
// public:
//     void dfs(vector<vector<int>>& image, int row, int col, int starting_color, vector<vector<int>>& ans, int color, vector<int> delrow, vector<int> delcol)
//     {
//         ans[row][col] = color;
//         int n = image.size();
//         int m = image[0].size();
        
//         for(int i=0; i<4; i++)
//         {
//             int nrow = row + delrow[i];
//             int ncol = col + delcol[i];
//             if((nrow>=0 && nrow<n)  &&  (ncol>=0 && col<m)  &&  image[nrow][ncol] == starting_color  &&  ans[nrow][ncol] != color)
//             {
//                 dfs(image, nrow, ncol, starting_color, ans, color, delrow, delcol);
//             }
//         }
//     }
    
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
//     {
//         vector<vector<int>> ans = image;
//         int starting_color = image[sr][sc];
        
//         vector<int> delrow = {-1, 0, 1, 0};
//         vector<int> delcol = {0, -1, 0, 1};
//         dfs(image, sr, sc, starting_color, ans, color, delrow, delcol);
//         return ans;
//     }
// };




class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, int starting_color, int color, vector<int> delrow, vector<int> delcol)
    {
        // cout << row << " " << col << endl;
        image[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        
        for(int i=0; i<4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if((nrow>=0 && nrow<n)  &&  (ncol>=0 && ncol<m)  &&  image[nrow][ncol] == starting_color  &&  image[nrow][ncol] != color)
            {
                dfs(image, nrow, ncol, starting_color, color, delrow, delcol);
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        // vector<vector<int>> ans = image;
        int starting_color = image[sr][sc];
        
        // cout << sr << " " << sc << endl;
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, -1, 0, 1};
        dfs(image, sr, sc, starting_color, newColor, delrow, delcol);
        return image;
    }
    
};