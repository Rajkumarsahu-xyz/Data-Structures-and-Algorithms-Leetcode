class Solution {
public:
    bool checkIfPangram(string sentence) 
    {
        vector<int> alp(26, 0);
        for(int i=0; i<sentence.length(); i++)
        {
            char x = sentence[i] - 97;
            alp[x] = 1;
        }
        
        for(char x : alp)
        {
            if(x == 0)
                return false;
        }
        
        return true;
    }
};