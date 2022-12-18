class Solution {
public:
    int similarPairs(vector<string>& words) 
    {
        int n = words.size();
        sort(words.begin(), words.end());
        int ctr=0;
        unordered_map<int, string> mp;
        for(int i=0; i<n; i++)
        {
            string s = "";
            sort(words[i].begin(), words[i].end());
            for(int j=0; j<words[i].length(); j++)
            {
                if(find(s.begin(), s.end(), words[i][j]) == s.end())
                {
                    s += words[i][j];
                }
            }
            
            mp[i] = s;
        }
        
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(mp[i] == mp[j])
                {
                    ctr++;
                }
            }
        }
        
        return ctr;
    }
};