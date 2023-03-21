class Solution {
public:
    bool checkZeroOnes(string s) 
    {
        int ctr1 = 0, mx1 = INT_MIN;
        int ctr0 = 0, mx0 = INT_MIN;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == '1')
            {
                mx0 = max(mx0, ctr0);
                ctr0 = 0;
                ctr1++;
            }
            
            if(s[i] == '0')
            {
                mx1 = max(mx1, ctr1);
                ctr1 = 0;
                ctr0++;
            }
        }
        
        if(ctr1 > 0)
            mx1 = max(mx1, ctr1);
        if(ctr0 > 0)
            mx0 = max(mx0, ctr0);
        
        // cout << mx1 << " " << mx0 << endl;
        return (mx1 > mx0);
    }
};