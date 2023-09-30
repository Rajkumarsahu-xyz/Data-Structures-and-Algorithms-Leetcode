//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to modify the matrix such that if a matrix cell matrix[i][j]
    //is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int> > &m)
   {
       unordered_set<int> row,col;
       int rs = m.size();
       int cl = m[0].size();
       for(int i=0;i<rs;i++)
       {
           for(int j=0;j<cl;j++){
               if(m[i][j]==1){
                   row.insert(i);
                   col.insert(j); 
               }
           }
       }
       
       for( auto r : row){
           for(int i=0;i<cl;i++){
               m[r][i]=1;
           }
       }
       for( auto c : col){
           for(int i=0;i<rs;i++){
               m[i][c]=1;
           }
       }
   }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        ob.booleanMatrix(matrix);


        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}



// } Driver Code Ends