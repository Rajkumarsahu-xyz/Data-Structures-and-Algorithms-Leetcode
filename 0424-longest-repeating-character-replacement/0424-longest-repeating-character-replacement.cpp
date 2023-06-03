class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int n = s.length();
        unordered_map<int, int> mp;
        
        int i=0, j=0;
        int mx = 0;
        char flip = ' ';
        int ans = 0;
        while(j<n)
        {
            mp[s[j]]++;
            if(mx < mp[s[j]])
            {
                mx =  mp[s[j]];
                flip = s[j];
            }
            
            // ans = max(ans, j-i);
            
            if((j-i+1)-mx == k)
            {
                ans = max(ans, j-i+1);
                // mp[s[i]]--;
                // if(mp[s[i]] == 0)
                //     mp.erase(s[i]);
                // i++;
            }
            
            
            if((j-i+1)-mx > k)
            {
                ans = max(ans, j-i);
                mp[s[i]]--;
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);
                i++;
            }
            
            else
            {
                ans = max(ans, j-i+1);
            }
            j++;
        }
        
        // if((j-i)-mx > k)
        // {
        //     ans = max(ans, j-i+1);
        // }
        
        return ans;
    }
};