//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      vector<long long> res;
      vector<int> rw(n+1,0);
      vector<int> col(n+1,0);
      int cr=n;
      int cc=n;
      
      
      for(auto ele: arr)
      {
          int r=ele[0];
          int c=ele[1];
          
          if(rw[r]==0)
                cr--;
          if(col[c]==0)
            cc--;
          rw[r]=1;
          col[c]=1;
          
          long long c1=cr,c2=cc;
        
        
          long long z=c1*n-(n-c2)*(c1);
          res.push_back(z);
      }
      return res;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends