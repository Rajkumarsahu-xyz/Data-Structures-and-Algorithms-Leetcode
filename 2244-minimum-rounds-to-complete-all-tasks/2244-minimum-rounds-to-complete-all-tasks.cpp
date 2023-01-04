class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        unordered_map<int, int> mp;
        for(int i=0; i<tasks.size(); i++)
        {
            mp[tasks[i]]++;
        }
        
        int ctr = 0;
        for(auto x : mp)
        {
            if(x.second < 2)
                return -1;
            else if(x.second%3 == 0)
                ctr += x.second/3;
            
            else if(x.second%3 == 2)
                ctr += (x.second/3 + 1);
            
            else if(x.second%3 == 1)
            {
                int k = x.second/3;
                ctr += (k-1) + 2;
            }
        }
        
        return ctr;
    }
};