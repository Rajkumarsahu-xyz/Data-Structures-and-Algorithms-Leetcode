class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char, int>> st;
        st.push({s[0], 1});
        int ctr=1;
        for(int i=1; i<s.length(); i++)
        {
            if(st.size() > 0  &&  st.top().first == s[i])
            {
                ctr++;
                st.top().second++;
                if(st.top().second == k)
                {
                    st.pop();
                }
            }
            else
            {
                st.push({s[i], 1});
            }
        }
        
        string ans="";
        while (!st.empty()) 
        {
            for(int i=0; i<st.top().second; i++)
            {
                ans += st.top().first;
            }
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};