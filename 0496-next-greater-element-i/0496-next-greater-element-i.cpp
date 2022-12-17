class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums2.size();
        stack<int> stk;
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i=n-1; i>=0; i--)
        {
            if(stk.size() == 0)
            {
                mp[nums2[i]] = -1;
            }

            else if(stk.size()>0  &&  stk.top()>nums2[i])
            {
                mp[nums2[i]] = stk.top();
            }

            else if(stk.size()>0  &&  stk.top()<=nums2[i])
            {
                while(stk.size()>0  &&  stk.top()<=nums2[i])
                {
                    stk.pop();
                }

                if(stk.size() == 0)
                {
                    mp[nums2[i]] = -1;
                }
                else
                {
                    mp[nums2[i]] = stk.top();
                }
            }

            stk.push(nums2[i]);
        }

        for(int i=0; i<nums1.size(); i++)
        {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};