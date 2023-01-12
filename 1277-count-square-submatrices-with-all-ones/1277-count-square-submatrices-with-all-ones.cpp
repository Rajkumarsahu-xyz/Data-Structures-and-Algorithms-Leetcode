class Solution {
public:
    int countSquares(vector<vector<int>>& a) 
    {
        int ctr = 0;
        int n = a.size(), m = a[0].size();
        for (int i = 1; i < n; i++) 
        {
            for (int j = 1; j < m; j++) 
            {
                if (a[i][j] == 0)
                    continue;
                a[i][j] = min( min(a[i-1][j], a[i][j-1]), a[i-1][j-1]) + 1;
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ctr += a[i][j];
            }
        }

        return ctr;
    }
};