class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        if(n == 1)
            return 1;
        unordered_map<int, pair<int, int>> mp;
        for(int i=0; i<trust.size(); i++)
        {
            mp[trust[i][0]].first++;
            mp[trust[i][1]].second++;
        }
        
        for(auto x : mp)
        {
            //cout<< x.first << " " << x.second << endl; 
            if(x.second.second == n-1 && x.second.first == 0)
            {
                return x.first;
            }
        }
        return -1;
    }
};