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
    
    int mxlen(vector<string>& arr, int i, int n, string subs, int mx)
    {
        if(unique(subs) == false)
            return mx;
        
        if(i==n)
        { 
            int len = subs.length();
            mx = max(mx, len);
            return mx;
        }
        
        mx = max(mxlen(arr, i+1, n, subs+arr[i], mx), mxlen(arr, i+1, n, subs, mx));
        return mx;
    }
    
    int maxLength(vector<string>& arr) 
    {
        int n = arr.size(), mx = 0;
        string subs = "";
        return mxlen(arr, 0, n, subs, mx);
        
        //return mx;
    }
};