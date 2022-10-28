class Solution {
public:
    
    bool unique(string& str)
    {
        vector<int> alphs(26);
        for(int i=0; i<str.size(); i++)
        {
            alphs[str[i]-'a']++;
        }
        
        for(int i=0; i<alphs.size(); i++)
        {
            if(alphs[i] > 1)
                return false;
        }
        
        return true;
    }
    
    int mxlen(vector<string>& arr, int i, int n, string subs, int mx, unordered_map<string, int>& dp)
    {
        if(unique(subs) == false)
            return mx;
        
        if(i==n)
        { 
            int len = subs.length();
            mx = max(mx, len);
            return mx;
        }
        
        if(dp.find(subs) != dp.end())
        {
            return dp[subs];
        }
        
        mx = max(mxlen(arr, i+1, n, subs+arr[i], mx, dp), mxlen(arr, i+1, n, subs, mx, dp));
        return dp[subs] = mx;
    }
    
    int maxLength(vector<string>& arr) 
    {
        int n = arr.size(), mx = 0;
        string subs = "";
        unordered_map<string, int> dp;
        return mxlen(arr, 0, n, subs, mx, dp);
    }
};