// class Solution {
// public:
    
//     int dp[1001][1001];
//     int subsequences(string text1, string text2, int m, int n)
//     {
//         if(m < 0 || n < 0)
//             return 0;
        
//         if(dp[m][n] != -1)
//             return dp[m][n];
        
//         if(text1[m] == text2[n])
//             return dp[m][n] = 1 + subsequences(text1, text2, m-1, n-1);
//         else
//         {
//             int c1 = subsequences(text1, text2, m-1, n);
//             int c2 =  subsequences(text1, text2, m, n-1);
//             return dp[m][n] = max(c1, c2);
//         }
//     }
    
//     int longestCommonSubsequence(string text1, string text2) 
//     {
//         int m = text1.length();
//         int n = text2.length();
//         // vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
//         memset(dp,-1,sizeof(dp));
//         return subsequences(text1, text2, m-1, n-1);
//     }
// };



class Solution {
public:
    int longestCommonSubsequence(string &text1, string &text2,int m,int n,int memo[][1001]) {
        if(m==0 || n==0){
            return 0;
        }
        if(memo[m][n]!=-1){
            return memo[m][n];
        }
        if(text1[m-1]==text2[n-1]){
            return memo[m][n]= 1+longestCommonSubsequence(text1,text2,m-1,n-1,memo);
        }else{
            return memo[m][n]= max(longestCommonSubsequence(text1,text2,m-1,n,memo),longestCommonSubsequence(text1,text2,m,n-1,memo));
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        int memo[1001][1001];
        for(int i=0;i<1001;i++){
            for(int j=0;j<1001;j++){
                memo[i][j]=-1;
            }
        }
        return longestCommonSubsequence(text1,text2,m,n,memo);
    }
};