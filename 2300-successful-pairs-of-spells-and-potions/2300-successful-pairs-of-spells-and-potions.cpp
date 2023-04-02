class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            long long temp = success/spells[i];
            auto itr = potions.begin();
            if(success%spells[i] != 0)
            {
                itr = upper_bound(potions.begin(), potions.end(), temp);
            }
            else
            {
                itr = lower_bound(potions.begin(), potions.end(), temp);
            }
            
            ans.push_back(m-(itr-potions.begin()));
        }
        
        return ans;
    }
};