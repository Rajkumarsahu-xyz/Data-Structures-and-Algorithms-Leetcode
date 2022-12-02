class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        vector<int> chars1(26), chars2(26);
        unordered_map<int, int> mp;
        
        for(int i=0; i<word1.length(); i++)
        {
            chars1[word1[i]-'a']++;
            mp[word1[i]-'a'] = 1;
        }
        
        for(int i=0; i<word2.length(); i++)
        {
            chars2[word2[i]-'a']++;
            if(mp.find(word2[i]-'a') == mp.end())
                return false;
        }
        
        sort(chars1.begin(), chars1.end());
        sort(chars2.begin(), chars2.end());
        
        return (chars1 == chars2);
    }
};