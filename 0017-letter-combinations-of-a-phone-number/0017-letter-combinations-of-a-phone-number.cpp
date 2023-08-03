class Solution {
public:
    
    vector<string> ans;
    void findCombinations(vector<char> keypad[], string digits, string res, int index, int n)
    {
        if (index == n) 
        {
            // cout << res << " ";
            // cout << endl;
            if(res != "")
                ans.push_back(res);
            return;
        }
        
        int len = keypad[digits[index]-48].size();

        for (int i = 0; i < len; i++) 
        {
            findCombinations(keypad, digits, res + keypad[digits[index]-48][i], index+1, n);
        }
    }
    
    vector<string> letterCombinations(string digits) 
    {
        vector<char> keypad[] =
        {
            {}, {},	 // 0 and 1 digit don't have any characters associated
            { 'a', 'b', 'c' },
            { 'd', 'e', 'f' },
            { 'g', 'h', 'i' },
            { 'j', 'k', 'l' },
            { 'm', 'n', 'o' },
            { 'p', 'q', 'r', 's'},
            { 't', 'u', 'v' },
            { 'w', 'x', 'y', 'z'}
        };
        
        int n = digits.length();

        findCombinations(keypad, digits, string(""), 0, n);
        return ans;
    }
};