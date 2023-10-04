//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        unordered_map< char , int > mpp  = {
            {'I' , 1}   ,
            {'V' , 5}   ,
            {'X' , 10}  ,
            {'L' , 50}  ,
            {'C' , 100} ,
            {'D' , 500} ,
            {'M' , 1000} 
        };
        
        int ans = mpp[str.back()] ;
        
        for(int i = 0 ; i < str.length() - 1 ; i++){
            if(mpp[str[i]] < mpp[str[i + 1]]){
                ans -= mpp[str[i]] ;
            }
            else{
                ans += mpp[str[i]] ;
            }
        } 
        
        return ans ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends