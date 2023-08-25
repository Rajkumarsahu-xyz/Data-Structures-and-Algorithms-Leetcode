class Solution {
public:
    
    bool leave(string s1, string s2, string s3, int n1, int n2, int n3, vector<vector<int>> &dp)
    {
        if(n1<0 && n2<0 && n3<0)
            return true;
        
        if(n1>=0 && n2>=0 && dp[n1][n2] != -1)
            return dp[n1][n2];
        
        else if(n1>=0 && s1[n1]==s3[n3] && n2>=0 && s2[n2]==s3[n3])
        {
            return dp[n1][n2] = (leave(s1, s2, s3, n1-1, n2, n3-1, dp) || leave(s1, s2, s3, n1, n2-1, n3-1, dp));
        }
        
        else if(n1>=0 && s1[n1]==s3[n3])
        {
            return leave(s1, s2, s3, n1-1, n2, n3-1, dp);
        }
        
        else if(n2>=0 && s2[n2]==s3[n3])
        {
            return leave(s1, s2, s3, n1, n2-1, n3-1, dp);
        }
        
        else
        {
            return false;
        }
    }
    
    bool isInterleave(string s1, string s2, string s3) 
    {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if(n1+n2 != n3)
            return false;
        
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        
        return leave(s1, s2, s3, n1-1, n2-1, n3-1, dp);
    }
};