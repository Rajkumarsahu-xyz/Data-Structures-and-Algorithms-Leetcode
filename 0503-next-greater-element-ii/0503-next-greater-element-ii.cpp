class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n = nums.size();
        stack<int> stk;
        vector<int> ans;
        
        for(int i=n-1; i>=0; i--)
        {
            stk.push(nums[i]);
        }
        
        for(int i=n-1; i>=0; i--)
        {
            if(stk.size()>0  &&  stk.top()>nums[i])
            {
                ans.push_back(stk.top());
            }

            else if(stk.size()>0  &&  stk.top()<=nums[i])
            {
                while(stk.size()>0  &&  stk.top()<=nums[i])
                {
                    stk.pop();
                }

                if(stk.size() == 0)
                {
                    ans.push_back(-1);
                }
                else
                {
                    ans.push_back(stk.top());
                }
            }

            stk.push(nums[i]);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};