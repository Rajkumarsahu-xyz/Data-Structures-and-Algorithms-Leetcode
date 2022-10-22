class Solution {
public:
    string minWindow(string s, string t) 
    {
        int n = s.length();

        unordered_map<char, int> mp(t.size());
        int count = 0;
        for(int i=0; i<t.length(); i++)
        {
            mp[t[i]]++;
        }
        count = mp.size();

        int mn = INT_MAX;
        int i=0, j=0;
        int start = 0;
        while(j<n)
        {
            if(mp.find(s[j])!=mp.end())
            {
                mp[s[j]]--;
                if (mp[s[j]] == 0)
                    count--;
            }

            if(count > 0)
            j++;

            else if(count == 0)
            {
                if(mn > j-i+1)
                {mn = min(mn, j-i+1);
                start = i;}

                while(count==0)
                {
                    if(mp.find(s[i])==mp.end())
                    {
                        i++;
                        if(mn > j-i+1)
                        {mn=min(mn,j-i+1);
                        start = i;}
                    }
                    else
                    {
                        mp[s[i]]++;
                        if(mp[s[i]]>0)
                        {
                            i++;
                            count++;
                        }
                        else
                        {
                            i++;
                            if(mn > j-i+1)
                            {mn=min(mn,j-i+1);
                            start = i;}
                        }
                    }
                }
                j++;
            }
        
        }
        return mn!=INT_MAX ? s.substr(start, mn) : "";
    }
};