class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int K) 
    {
        int N = nums.size();
        int i=0, j=0;
        list<int> l;
        vector<int> ans;

        while(j<N)
        {
            while(l.size()>0 && l.back() < nums[j])
            {
                l.pop_back();
            }
            l.push_back(nums[j]);
        
            if(j-i+1 < K)
            j++;

            else if(j-i+1 == K)
            {
                ans.push_back(l.front());

                if(l.front()==nums[i])
                l.pop_front();

                i++; j++;
            }
        }
        
        return ans;
    }
};