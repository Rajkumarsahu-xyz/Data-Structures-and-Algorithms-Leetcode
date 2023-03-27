class Solution {
public:
    
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<vector<int>> mat(n, vector<int>(n, 1e9));
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i == j)
                    mat[i][j] = 0;
            }
        }
        
        for(int i=0; i<edges.size(); i++)
        {
            mat[edges[i][0]][edges[i][1]] = edges[i][2];
            mat[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        
        for (int k = 0; k < n; k++) 
        {
			for (int i = 0; i < n; i++) 
			{
				for (int j = 0; j < n; j++) 
				{
					if (mat[i][k] == 1e9  ||  mat[k][j] == 1e9)
						continue;
					
					mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
				}
			}
		}
        
        int mn = INT_MAX;
        int mncity = 0;
        for(int i=0; i<n; i++)
        {
            int ctr = 0;
            for(int j=0; j<n; j++)
            {
                if(mat[i][j] <= distanceThreshold)
                    ctr++;
            }
            
            if(ctr < mn)
            {
                mncity =  i;
                mn = ctr;
            }
            if(ctr == mn)
            {
                mncity = max(mncity, i);
            }
        }
        
        return mncity;
    }

};