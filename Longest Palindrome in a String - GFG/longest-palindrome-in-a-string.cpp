//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public :
    int palindrome(string s,int i,int j){
         while(i>=0 && j<s.size()){
             if(s[i]!=s[j]){
                break;
             }
             else{
                 j++;
                 i--;
             }
         }
         return j-i-1;
     }
     string longestPalin(string s){
        
        
        int index=0;
        int mxl=0;
          for(int i=0;i<s.size();i++){
             int value1=palindrome(s,i,i+1);// for even length substring
             int value2=palindrome(s,i,i);// for odd length substring
            int  maxy=max(value1,value2);
             if(maxy>mxl){
                 mxl=maxy;
                 
                 index=i-(maxy-1)/2;
         
          
          
             
             }
            
             
          }
          
           return s.substr(index,mxl);
          
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends