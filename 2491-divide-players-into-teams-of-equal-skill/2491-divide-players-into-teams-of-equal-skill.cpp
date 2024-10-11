class Solution {
public:
    long long dividePlayers(vector<int>& skill) 
    {
        long long n = skill.size();
        unordered_map<long long, long long> mp;
        
        sort(skill.begin(), skill.end());
        
        long long i=0, j=n-1;
        while(i<j) 
        {
            mp[skill[i] + skill[j]] = mp[skill[i] + skill[j]] + skill[i] * skill[j];
            i++; j--;
        }
        
        if(mp.size() != 1)
        {
            return -1;
        }
        
        return mp[skill[0] + skill[n-1]];
    }
};