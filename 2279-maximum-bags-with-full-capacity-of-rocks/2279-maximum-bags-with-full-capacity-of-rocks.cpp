class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        vector<int> leftrocks;
        for(int i=0; i<rocks.size(); i++)
        {
            leftrocks.push_back(capacity[i]-rocks[i]);
        }
        sort(leftrocks.begin(), leftrocks.end());
        
        int ans = 0;
        for(auto x : leftrocks)
        {
            if(x > additionalRocks)
                break;
            
            additionalRocks -= x;
            ans++;
        }
        
        return ans;
    }
};