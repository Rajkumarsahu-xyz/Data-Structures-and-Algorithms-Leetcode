class Solution {
public:
    int partitionString(string s) 
    {
        int n = s.length();
        int i=0, j=0;
        
        unordered_map<int, int> mp;
        int ctr = 0;
        while(j<n)
        {
            mp[s[j]]++;
            if(mp.size() < j-i+1)
            {
                ctr++;
                mp.clear();
                i = j;
                continue;
            }
            j++;
        }
        
        return ctr+1;
    }
};