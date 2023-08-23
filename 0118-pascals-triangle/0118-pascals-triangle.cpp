class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        if(numRows == 1)
            return {{1}};
        else if(numRows == 2)
            return {{1}, {1, 1}};
        
        vector<vector<int>> ans;
        ans.push_back({1});
        ans.push_back({1, 1});
        
        for(int i=2; i<numRows; i++)
        {
            int n = ans[i-1].size();
            vector<int> v(n+1, 1);
            for(int j=1; j<(n+1)-1; j++)
            {
                v[j] = ans[i-1][j] + ans[i-1][j-1];
            }
            ans.push_back(v);
        }
        
        return ans;
    }
};