class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        unordered_map<int,int> win, loss;
        int n = matches.size();
        for(int i=0; i<n; i++)
        {
            win[matches[i][0]]++;
            loss[matches[i][1]]++;
        }
        
        vector<vector<int>> answer;
        vector<int> w, l; 
        for(auto x : win)
        {
            if(loss.find(x.first) == loss.end())
            {
                w.push_back(x.first);
            }
        }
        
        for(auto x : loss)
        {
            if(x.second == 1)
            {
                l.push_back(x.first);
            }
        }
        
        sort(w.begin(), w.end());
        sort(l.begin(), l.end());
        answer.push_back(w);
        answer.push_back(l);
        
        return answer;
    }
};