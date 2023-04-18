class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        int n1 = word1.length(), n2 = word2.length();
        
        int i=0, j=0;
        string ans = "";
        while(i<n1 && j<n2)
        {
            ans += word1[i];
            ans += word2[j];
            i++; j++;
        }
        
        if(i<n1)
        {
            while(i<n1)
            {
                ans += word1[i];
                i++;
            }
        }
        
        if(j<n2)
        {
            while(j<n2)
            {
                ans += word2[j];
                j++;
            }
        }
         
        return ans;
    }
};