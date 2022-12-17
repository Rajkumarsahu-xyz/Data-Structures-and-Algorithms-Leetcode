class Solution {
public:
    vector<int> intersect(vector<int>& v1, vector<int>& v2) 
    {
        vector<int>ans;
        sort(v2.begin(), v2.end());
        for(int i=0; i<v1.size(); i++)
        {
            int var=lower_bound(v2.begin(),v2.end(),v1[i]) - v2.begin();
            if(var<v2.size() && v2[var]==v1[i])
            {
                auto it=v2.begin()+var;
                ans.push_back(v1[i]);
                v2.erase(it);
            }
        }
        return ans;
    }
};