class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        unordered_map<string,int> mp;
        
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j] != '.')
                {
                    int k = (j/3) + ((i/3) * 3);
                    string row = "row "+to_string(i)+" "+to_string(board[i][j]);
                    string col = "col "+to_string(j)+" "+to_string(board[i][j]);
                    string box = "box "+to_string(k)+" "+to_string(board[i][j]);
                    
                    
                    if(!mp.count(row) && !mp.count(col) && !mp.count(box))
                    {
                        mp[row]++;
                        mp[col]++;
                        mp[box]++;
                    }
                    
                    else
                       return false;
                }
            }
        }
        
        return true;
    }
};