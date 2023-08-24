class Solution {
public:
    string reorganizeString(string s) 
    {
        int n = s.length();
        string ans;
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;
        
        int mx = INT_MIN;
        for(int i=0; i<n; i++)
        {
            mp[s[i]]++;
            // mx = max(mx, mp[s[i]]);
        }
        
        for(auto x : mp)
        {
            pq.push({x.second, x.first});
        }
        
        
        // cout << 5 + 'a' << endl;
        
        while(!pq.empty())
        {
            int freq = pq.top().first;
            char key = pq.top().second;
            pq.pop();
            
            if(ans.length() == 0 || ans[ans.length()-1] != key)
            {
                ans += key;
                freq--;
                if(freq)
                    pq.push({freq, key});
            }
            
            else if(!pq.empty())
            {
                int freq2 = pq.top().first;
                int key2 = pq.top().second;
                pq.pop();
                
                ans += key2;
                freq2--;
                if(freq2)
                    pq.push({freq2, key2});
                pq.push({freq, key});
            }
            else
            {
                return "";
            }
        }
        return ans;
    }
};