class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n = nums.size();
        nums.resize(2*n);
        
        for(int i=n; i<2*n; i++)
        {
            nums[i] = nums[i-n];
        }
        
        stack<int> stk;
        vector<int> ans;
        for(int i=(2*n)-1; i>=0; i--)
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
        ans.resize(n);
        return ans;
    }
};