class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        int n = piles.size();
        priority_queue<int> pq(piles.begin(), piles.end()); 
        
        while(k--)
        {
            int x = pq.top();
            pq.pop();
            if(x%2 == 0)
                pq.push(x/2);
            else
                pq.push((x/2)+1);
        }
        
        int stones=0;
        while(!pq.empty())
        {
            stones += pq.top();
            pq.pop();
        }
        
        return stones;
    }
};