class Solution {
public:
    int countHomogenous(string s) 
    {
        long long n = s.length();
        long long i=0, j=0, ctr=0;
        unordered_map<char, long long> mp;
        long long c = 0;
        
        while(j<n)
        {
//             if (mp[s[j]] > 0) 
//             {
//                 c += mp[s[j]];
//             }
//             mp[s[j]]++;
//             while(i<=j && mp[s[j]]<(j-i+1))
//             {
//                 ctr += (n-j);
//                 mp[s[i]]--;
//                 c -= mp[s[i]];
//                 i++;
//             }
            
//             j++;
            
            mp[s[j]]++;
            if(mp[s[j]]==(j-i+1))
                c += mp[s[j]];
            while(i<=j && mp[s[j]]<(j-i+1))
            {
                mp[s[i]]--;
                c = 1;
                i++;
            }
            ctr = (ctr+c)%(1000000007);
            c = 0;
            j++;
        }
        
        return ctr%(1000000007);
    }
};