class Solution {
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int n = strs[0].length();
        int ctr = 0;
        for(int i=0; i<n; i++)
        {
            char prev = strs[0][i];
            for(int j=1; j<strs.size(); j++)
            {
                if(prev > strs[j][i])
                {
                    ctr++;
                    break;
                }
                prev = strs[j][i];
            }
        }
        
        return ctr;
    }
};