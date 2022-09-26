class Solution {
public:
    int uf_find(vector<int> &uf, int i) 
    {
        return uf[i] = (uf[i] == -1 || uf[i] == i) ? i : uf_find(uf, uf[i]);
    }
    bool equationsPossible(vector<string>& equations) 
    {
        vector<int> uf('z' + 1, -1);
        for (auto s : equations)
            if (s[1] == '=') 
                uf[uf_find(uf, s[0]-'a')] = uf_find(uf, s[3]-'a');
        
        for (auto s : equations)
            if (s[1] == '!' && uf_find(uf, s[0]-'a') == uf_find(uf, s[3]-'a')) 
                return false;
        
        return true;
    }
};