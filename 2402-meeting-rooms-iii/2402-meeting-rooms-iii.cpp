class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        sort(meetings.begin(), meetings.end());
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> engaged;
        priority_queue<int, vector<int>, greater<int>> unused;
        unordered_map<int, int> freq;

        for(int i = 0; i < n; i++) 
        {
            unused.push(i);
        }
        
        for(auto x:meetings) 
        {
            int s = x[0], e = x[1];
            while(engaged.size() > 0 && engaged.top().first <= s) 
            {
                int room = engaged.top().second;
                engaged.pop();
                unused.push(room);
            }
            
            if(unused.size() > 0) 
            {
                int room = unused.top();
                unused.pop();
                freq[room]++;
                engaged.push({e, room});
            }
            
            else 
            {
                pair<long long, int> topmost = engaged.top();
                engaged.pop();
                
                freq[abs(topmost.second)]++;
                long long newEnd = topmost.first;
                newEnd += (e - s);
                engaged.push({newEnd, topmost.second});
            }
        }
        
        int mx = 0;
        for(int i = 1; i < n; i++) 
        {
            if(freq[i] > freq[mx])
                mx = i;
        }
        return mx;
    }
};