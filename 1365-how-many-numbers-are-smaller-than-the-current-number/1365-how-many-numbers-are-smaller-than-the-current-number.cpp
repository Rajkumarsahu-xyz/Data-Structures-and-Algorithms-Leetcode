class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        vector<int> ans, temp;
        temp = nums;
        sort(temp.begin(), temp.end());
        for(int i=0; i<nums.size(); i++)
        {
            auto itr = lower_bound(temp.begin(), temp.end(), nums[i]);
            ans.push_back(itr-temp.begin());
        }
        return ans;
    }
};