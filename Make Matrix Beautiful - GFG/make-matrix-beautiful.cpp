//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends




class Solution
{
    public:
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int maxV=-1,s1,s2,total=0; 
        
        for(int i=0; i<n; i++){
            s1 = 0;
            s2 = 0;
            for(int j=0; j<n; j++){
                s1 += matrix[i][j];
                s2 += matrix[j][i];
            }
            maxV = max(maxV,max(s1,s2));
            total += s1;
        }
        return (n*maxV - total);    //This gives value of operations
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends