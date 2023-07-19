class Solution {
public:
    int maximizeGreatness(vector<int>& nums) 
    {
        int n = nums.size();
        priority_queue<int> pq;
        for(int i=0; i<n; i++)
        {
            pq.push(nums[i]);
        }
        
        sort(nums.begin(), nums.end(), greater<int>());
        int i=0, ctr = 0;
        pq.pop();
        while(i<n && !pq.empty())
        {
            int val = pq.top();
            pq.pop();
            if(val < nums[i])
            {
                ctr++;
                i++;
            }
        }
        
        return ctr;
    }
};