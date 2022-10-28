class Solution {
public:
    // string x;
    // static bool isEqual(const std::pair<std::string,  vector<string>>& element)
    // {
    //     return element.first ==  x;
    // }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        //vector<pair<string, vector<string>>> v;
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        
        int j=0;
//         for(int i=0; i<strs.size(); i++)
//         {
//             x = strs[i];
//             sort(x.begin(), x.end());
            
//             auto it = std::find_if(v.begin(), v.end(), isEqual);
//             if(it != v.end())
//             {
//                 it->second.push_back(strs[i]);
//             }
            
//             else
//             {
//                 v.push_back({x, {strs[i]}});
//             }
//         }
        
        for(int i=0; i<strs.size(); i++)
        {
            string x = strs[i];
            sort(x.begin(), x.end());
            mp[x].push_back(strs[i]);
        }
        
        
        for(auto t : mp)
        {
            ans.push_back(t.second);
        }
        
        return ans;
    }
};