class Solution {
public:
    string sortVowels(string s) 
    {
        string t = s;
        string temp = "";
        // unordered_map<char, int> mp;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                temp += s[i];
                t[i] = '#';
            }
        }
        
        sort(temp.begin(), temp.end());
        // cout << temp << endl;
        
        for(int i=t.length()-1; i>=0; i--)
        {
            if(t[i] == '#')
            {
                t[i] = temp[temp.length()-1];
                temp.pop_back();
            }
        }
        
        return t;
    }
};