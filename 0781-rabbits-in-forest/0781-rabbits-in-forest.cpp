class Solution {
public:
    int numRabbits(vector<int>& answers)
    {
        map<int, int> mp;
        for(int i=0; i<answers.size(); i++)
        {
            mp[answers[i]]++;
        }
        
        int ctr = 0;
        for(auto x : mp)
        {
            if(x.first == 0)
            {
                ctr += x.second;
            }
            else
            {
                if(x.second<x.first)
                    ctr += (x.first+1);
                else
                {
                    int k = x.second/(x.first+1);
                    if(x.second%(x.first+1) != 0)
                        k++;
                    int q = k*(x.first+1);
                    ctr += x.second + (q-x.second);
                }
            }
        }
        
        return ctr;
    }
};