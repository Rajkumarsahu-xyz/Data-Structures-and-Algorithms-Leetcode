class Solution {
public:
    static bool comp(pair<char, int>& a, pair<char, int>& b)
    {
        return a.second > b.second;
    }
    
    string frequencySort(string s) 
    {
        unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++)
        {
            mp[s[i]]++;
        }
        
        vector<pair<char, int>> A;
        for(auto it : mp) 
        {
            A.push_back(it);
        }

        sort(A.begin(), A.end(), comp);
        
        string ans = "";
        for(auto x : A)
        {
            while(x.second > 0)
            {
                ans += x.first;
                x.second--;
            }
        }
        
        return ans;
    }
};