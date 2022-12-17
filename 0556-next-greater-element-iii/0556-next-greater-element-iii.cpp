class Solution {
public:
    int nextGreaterElement(int n) 
    {
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        long long ans = stoll(s);
        
        if(ans > INT_MAX  || ans <= n)
            return -1;
        else 
            return ans;
    }
};