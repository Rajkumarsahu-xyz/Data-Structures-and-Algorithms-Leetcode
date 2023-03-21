class Solution {
public:
    int maxVowels(string s, int k) 
    {
        int n = s.size();
        int i=0, j=0;
        int ctr = 0, mx = INT_MIN;

        while(j<n)
        {
            if(s[j] == 'a'||s[j] == 'e'||s[j] == 'i'||s[j] == 'o'||s[j] == 'u' )
                ctr++;

            if(j-i+1 < k)
                j++;

            else if(j-i+1 == k)
            {
                mx = max(ctr, mx);
                if(s[i] == 'a'||s[i] == 'e'||s[i] == 'i'||s[i] == 'o'||s[i] == 'u')
                    ctr--;
                j++;
                i++;    
            }        
        }
        
        return mx;
    }
};