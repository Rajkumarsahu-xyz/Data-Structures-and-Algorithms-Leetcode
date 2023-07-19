class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) 
    {
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<profit.size(); i++)
        {
            pq.push({profit[i], difficulty[i]});
        }
        sort(worker.begin(), worker.end(), greater<int>());
        int sum = 0, i=0;
        while(i<worker.size() && !pq.empty())
        {
            int diff = pq.top().second;
            int val = pq.top().first;
            pq.pop();
            if(worker[i] >= diff)
            {
                while(i<worker.size() && worker[i] >= diff)
                {
                    // cout << val << " " << diff << endl;
                    sum += val;
                    i++;
                }
            }
            
        }
        
        return sum;
        
    }
};