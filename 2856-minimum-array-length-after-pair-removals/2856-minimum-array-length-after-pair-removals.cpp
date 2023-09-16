class Solution {
public:
    
    
    int minLengthAfterRemovals(vector<int>& nums) 
    {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mp;
        for(int i=0;i <n; i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto x : mp)
        {
            pq.push({x.second, x.first});
        }
        
        if(pq.size() == 1)
            return n;
        
        while(!pq.empty() && pq.size() > 1)
        {
            auto a = pq.top();
            pq.pop();
            auto b = pq.top();
            pq.pop();
            
            a.first--;
            b.first--;
            
            if(a.first > 0)
                pq.push(a);
            if(b.first > 0)
                pq.push(b);
        }
        
        if(pq.empty())
            return 0;
        else
            return pq.top().first;
        
        
//         unordered_map<int,int>m,m1;
//         for(auto x : nums)
//         {
//             m1[x]++;
//         }
//          if(m1.size()==1)
//             return n;
//         int ans=0;
//         int temp=0;
//         vector<int>v;
//         for(auto x : m1)
//         {
//             v.push_back(x.second);
//         }
//         sort(v.begin(),v.end(),greater<int>());
       
//         for(auto x : v)
//         {
//             temp = abs(temp - x);
//         }
       
//         return temp;
        
        
    }
};