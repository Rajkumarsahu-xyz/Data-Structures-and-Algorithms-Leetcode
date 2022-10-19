class Solution {
public:
//     static bool comp(pair<string, int>& a, pair<string, int>& b)
//     {
//         return a.second > b.second;
        
//     }
    
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        sort(words.begin(), words.end());
        map<string, int> mp;
        vector<string> ans;
        
        for(int i=0; i<words.size(); i++)
        {
            mp[words[i]]++;
        }
        
        multimap<int, string, greater<int>> mmp;
        
        for (auto& it : mp) 
        {
            mmp.insert({ it.second, it.first });
        }
        
        // for(auto x: mmp)
        // {
        //     cout << (x.first) << " " << x.second << " ";
        // }
        // cout << endl;
        
        //sort(A.begin(), A.end(), comp);
        
        // for(auto x: mmp)
        // {
        //     cout << (x.second) << " " << x.first << " ";
        // }
        // cout << endl;
        
        
        for(auto x: mmp)
        {
            if(k > 0)
                ans.push_back(x.second);
            else
                break;
            
            k--;
        }
        
        return ans;
    }
};