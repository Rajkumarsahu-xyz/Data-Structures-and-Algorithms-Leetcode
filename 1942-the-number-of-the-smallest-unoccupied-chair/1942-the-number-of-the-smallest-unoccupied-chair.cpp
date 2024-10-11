class Solution {
public:
    static bool sortbysec(const pair<int, vector<int>> &a, const pair<int, vector<int>> &b)
    {
        return (a.second < b.second);
    }
    
    int smallestChair(vector<vector<int>>& times, int targetFriend) 
    {
        int n = times.size();
        
        vector<pair<int, vector<int>>> pr;
        for(int i=0; i<n; i++)
        {
            pr.push_back(make_pair(i, times[i]));
        }
        sort(pr.begin(), pr.end(), sortbysec);
        
        priority_queue<int, vector<int>, greater<int>> emptyChairs; // current empty chairs
        for(int i=0; i<n; i++)
        {
            emptyChairs.push(i);
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs; // leaving time and occupied chair
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int arrivalTime = pr[i].second[0]; 
            int leavingTime = pr[i].second[1]; 
            if(!occupiedChairs.empty())
            {
                while(!occupiedChairs.empty() && arrivalTime >= occupiedChairs.top().first)
                {
                    emptyChairs.push(occupiedChairs.top().second);
                    occupiedChairs.pop();
                }
            }
            
            if(pr[i].first == targetFriend)
            {
                ans = emptyChairs.top();
                break;
            }
            
            else 
            {
                int emptyChair = emptyChairs.top();
                emptyChairs.pop();
                occupiedChairs.push(make_pair(leavingTime, emptyChair));
            }
        }
        
        return ans;
    }
};