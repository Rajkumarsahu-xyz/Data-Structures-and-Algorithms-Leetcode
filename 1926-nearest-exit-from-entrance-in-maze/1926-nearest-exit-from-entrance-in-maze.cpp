class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        int m = maze.size(), n = maze[0].size();
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        queue<array<int, 3>> q;
        q.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';
        
        int ctr = 0;
        
        while(!q.empty())
        {
            auto [i, j, currDis] = q.front();
            q.pop();
            
            for(auto x : dirs)
            {
                int nextRow = i + x.first, nextCol = j + x.second;
                if (0 <= nextRow && nextRow < m && 0 <= nextCol && nextCol < n && maze[nextRow][nextCol] == '.') 
                {
                    if (nextRow==0 || nextRow==m-1 || nextCol==0 || nextCol==n-1)
                    {
                        return currDis+1;
                    }
                    
                    maze[nextRow][nextCol] = '+';
                    q.push({nextRow, nextCol, currDis+1});
                }
            }
        }
        
        return -1;
    }
};