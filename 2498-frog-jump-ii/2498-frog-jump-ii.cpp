class Solution {
public:
    int maxJump(vector<int>& stones) 
    {
        int  mx = stones[1]-stones[0];
        
        for(int i=0; i < stones.size(); i++)
        {
            if(i+2 < stones.size()) 
                mx = max(mx, stones[i+2]-stones[i]);
        }
        
        return mx;
    }
};