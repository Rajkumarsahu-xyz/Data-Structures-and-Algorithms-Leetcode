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
            if (mp[s[j]] > 0) 
            {
                c += mp[s[j]];
            }
            mp[s[j]]++;
            while(i<=j && mp[s[j]]<(j-i+1))
            {
                ctr = (ctr+(n-j)) % (1000000007);
                mp[s[i]]--;
                c -= mp[s[i]];
                i++;
            }
            
            j++;
        }
        
        return ((n*(n+1)/2) - ctr) % (1000000007);
    }
};