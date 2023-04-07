class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        int n = s.length();
        unordered_map<char, int> mp;
        for(int i=0; i<n; i++)
        {
            mp[s[i]] = i;
        }
        
        int j = 0, k = 0;
        vector<int> ans;
        
        for(int i=0; i<n; i++)
        {
            if(j < mp[s[i]])
                j = mp[s[i]];
            if(i == j)
            {
                ans.push_back(j-k+1);
                k = i+1;
            }
        }
        
        return ans;
    }
};