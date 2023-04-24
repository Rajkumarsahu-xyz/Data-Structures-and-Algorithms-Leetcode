class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        make_heap(stones.begin(), stones.end());
        
         while (stones.size() > 1) {
            int x = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            
            int y = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            
            if (x == y) continue;
            
            stones.push_back(x - y);
            push_heap(stones.begin(), stones.end());
        }
        
        return stones.size() ? stones.front() : 0;
    }
};