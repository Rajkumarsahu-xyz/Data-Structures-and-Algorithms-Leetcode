class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        unordered_map<int,int> mp;
        
        int longestSubSeq = 1;
        
        for(auto &it : arr) 
        {
            if(mp.count(it - difference) == 0) 
            {
                mp[it] = 1;
            }
            else 
            {
                mp[it] = mp[it - difference]+1;
            }
            longestSubSeq = max(longestSubSeq , mp[it]);
        }
        return longestSubSeq;
    }
};