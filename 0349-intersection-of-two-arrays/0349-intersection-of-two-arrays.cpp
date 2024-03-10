class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        int n = nums1.size(), m = nums2.size();
        
        unordered_map<int, char> mp;
        for(int i=0; i<n; i++)
        {
            mp[nums1[i]] = 't';
        }
        
        for(int i=0; i<m; i++)
        {
            if(mp.find(nums2[i]) != mp.end()  &&  mp[nums2[i]] == 't') 
            {
                mp[nums2[i]] = 'f';
            }
        }
        
        vector<int> ans;
        
        for(auto x : mp)
        {
            if(x.second == 'f')
            {
                ans.push_back(x.first);
            }
        }
        
        return ans;
    }
};