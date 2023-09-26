class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26,0)  , vis(26,0);
        
        string res = "";
        int n = s.size();
        
        for(int i = 0; i<n; ++i)
            cnt[s[i] - 'a']++;
        
        for(int i = 0; i<n; ++i)
        {
            cnt[s[i] - 'a']--;
            if(!vis[s[i]- 'a'])
            {
                while(res.size() > 0 && res.back() > s[i] && cnt[res.back() - 'a'] > 0)
                {
                    vis[res.back() - 'a'] = 0;
                    res.pop_back();
                }
                res += s[i];
                vis[s[i] - 'a'] = 1;
            }
        }
        
        return res;
    }
};













// class Solution {
// public:
//     string removeDuplicateLetters(string s) 
//     {
//         int n = s.length();
        
//         vector<int> chars(26, 0);
//         for(int i=0; i<n; i++)
//         {
//             chars[s[i]-'a']++;
//         }
        
//         priority_queue<char, vector<char>, greater<char>> pq;
        
//         for(int i=0; i<26; i++)
//         {
//             if(chars[i] > 0)
//                 pq.push(char(i+97));
//         }
        
//         string ans = "";
//         for(int i=0; i<n; i++)
//         {
//             if(chars[s[i]-'a'] == 1)
//             {
//                 ans += s[i];
//                 chars[s[i]-'a']--;
//             }
            
//             else if(pq.top() == s[i])
//             {
//                 ans += s[i];
//                 pq.pop();
//                 chars[s[i]-'a']--;
//             }
            
//             else
//             {
//                 chars[s[i]-'a']--;
//             }
//         }
        
//         return ans;
//     }
// };