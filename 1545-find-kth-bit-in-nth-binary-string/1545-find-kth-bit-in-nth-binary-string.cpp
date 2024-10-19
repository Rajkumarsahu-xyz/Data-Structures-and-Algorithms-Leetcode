class Solution {
public:
    char findKthBit(int n, int k) 
    {
        if(n == 1)
            return '0';
        
        string S = "0";
        string Sn = "";
        for(int i=2; i<=n; i++)
        {
            Sn = S + "1";
            for(int j=S.length()-1; j>=0; j--)
            {
                if(S[j]=='0')
                    Sn += "1";
                else
                    Sn += "0";
            }
            S = Sn;
        }
        
        return Sn[k-1];
    }
};