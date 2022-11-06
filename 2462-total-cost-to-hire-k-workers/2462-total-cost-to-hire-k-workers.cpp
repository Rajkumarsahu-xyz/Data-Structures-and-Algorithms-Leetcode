class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cand) 
    {
        priority_queue<int, vector<int>, greater<int>> lpq, rpq;
        long long ans = 0;
        
        int i=0, j=costs.size()-1;
        while(k--)
        {
            while(lpq.size()<cand  &&  i<=j) 
                lpq.push(costs[i++]);
            while(rpq.size()<cand  &&  j>=i) 
                rpq.push(costs[j--]);
            
            int l = 1e9, r = 1e9;
            if(lpq.size() > 0)
                l = lpq.top();
            if(rpq.size() > 0)
                r = rpq.top();
            
            if(l <= r)
            {
                ans += l;
                lpq.pop();
            }
            else
            {
                ans += r;
                rpq.pop();
            }
            //cout << ans << " " ;
        }
        
        return ans;
    }
};