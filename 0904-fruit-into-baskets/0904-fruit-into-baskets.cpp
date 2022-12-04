class Solution {
public:
    int totalFruit(vector<int>& fruits) 
    {
        unordered_map<int, int> mp;
        int n = fruits.size();
        int i=0, j=0, mx=0;
        
        while(j<n)
        {
            mp[fruits[j]]++;
            if(mp.size() <= 2)
            {
                mx = max(mx, j-i+1);
                j++;
            }
            
            else if(mp.size() > 2)
            {
                while(mp.size() > 2)
                {
                    mp[fruits[i]]--;
                    if(mp[fruits[i]] == 0) 
                        mp.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        
        return mx;
    }
};