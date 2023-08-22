class Solution {
public:
    string convertToTitle(int columnNumber) 
    {
        int a = columnNumber;
        string ans;
        while(a > 0)
        {
            a--;
            int r = a%26;
            char t = ('A'+r);
            ans = t + ans;
            a /= 26;
        }
        
        return ans;
    }
};
