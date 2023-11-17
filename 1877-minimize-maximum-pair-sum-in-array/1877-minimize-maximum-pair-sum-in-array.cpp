class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        priority_queue<int>v1;
        priority_queue<int,vector<int>,greater<int>>v2;
        
        for(int i:nums)
        {
            v1.push(i);
            v2.push(i);
        }
        
        int mx = 0;
        while(!v1.empty())
        {
            mx = max(mx, v1.top() + v2.top());
            v1.pop();
            v2.pop();
        }
        return mx;
    }
};