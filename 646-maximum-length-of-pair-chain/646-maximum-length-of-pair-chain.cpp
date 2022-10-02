class Solution {
public:
    int dp[1001][1001];
    int chain(vector<vector<int>>& pairs, int start, int last,int len)
    {
        if(start >= pairs.size())
            return 0;
        if(dp[start][last+1] != -1)
            return dp[start][last+1];
        int inc=0,notInc=0;
        // will include this element
        if(last==-1 || pairs[start][0] > pairs[last][1])
            inc = 1 + chain(pairs,start+1,start,len+1);
        // will not include
        notInc = chain(pairs,start+1,last,len);
        return dp[start][last+1] = max(inc,notInc);
    }
    
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        int n = pairs.size();
        if(n==1)
          return n;
        memset(dp,-1,sizeof(dp));
        sort(pairs.begin(), pairs.end());
        int start=0, last=-1,len=0;
        return chain(pairs,start,last,len);
    }
};