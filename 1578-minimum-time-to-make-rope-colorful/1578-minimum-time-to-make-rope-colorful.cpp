class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        int mn = 0;
        int prev = neededTime[0];
        for(int i=0; i<colors.length()-1; i++)
        {
            if(colors[i] == colors[i+1])
            {
                mn += min(prev, neededTime[i+1]);
                prev = max(prev, neededTime[i+1]);
            }
            else
                prev = neededTime[i+1];
        }
        
        return mn;
    }
};