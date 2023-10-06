// class Solution {
// public:
//     int intBreak(int n, vector<int> &dp) 
//     {
//         if(n==0 || n==1)
//             return 1;
        
//         if(dp[n] != -1)
//             return dp[n];
        
//         int mx = 0;
//         for(int i=1; i<n; i++)
//         {
//             mx = max(mx, max(intBreak(n-i,dp)*i, i*(n-i)));
//         }
        
//         return dp[n] = mx;
//     }
    
//     int integerBreak(int n) 
//     {
//         vector<int> dp(n, -1);
//         return integerBreak(n, dp);
//     }
// };





class Solution {
public:
    vector<int> memo;
    
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        
        memo = vector(n + 1, 0);
        return dp(n);
    }
    
    int dp(int num) {
        if (num <= 3) {
            return num;
        }
        
        if (memo[num] != 0) {
            return memo[num];
        }
        
        int ans = num;
        for (int i = 2; i < num; i++) {
            ans = max(ans, i * dp(num - i));
        }
        
        memo[num] = ans;
        return ans;
    }
};

