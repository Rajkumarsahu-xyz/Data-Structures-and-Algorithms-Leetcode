class Solution {
public:
    int longestContinuousSubstring(string s) 
    {
        int ctr = 1, mx = INT_MIN;
        // char ch = 'a';
        for(int i=1; i<s.length(); i++)
        {
            if(s[i] == s[i-1]+1)
            {
                // cout << ctr << " a1 " << ch << endl;
                ctr++;
            }
            
            else
            {
                mx = max(mx, ctr);
                ctr = 1;
                // cout << ctr << " b1 " << ch << endl;
            }
        }
        
        if(ctr > 0)
            mx = max(mx, ctr);
        
        return mx;
    }
};