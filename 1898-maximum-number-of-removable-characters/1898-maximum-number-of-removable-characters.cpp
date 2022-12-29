class Solution {
public:
    bool isValid(string s, string p, vector<int>& removables, int k, vector<char>& charArrStringS) 
    {
        for (int i = 0; i <= k; i++) 
        {
            charArrStringS[removables[i]] = '#';
        }
        
        int i = 0, j = 0;
        while (i < charArrStringS.size() && j < p.length()) 
        {
            if (charArrStringS[i] == '#') 
            {
                i++;
                continue;
            }
            
            if (charArrStringS[i] == p[j]) 
            {
                i++; j++;
            } 
            else 
            {
                i++;
            }
        }
        
        
        if (j == p.length()) return true;
        for (int i = 0; i <= k; i++) 
        {
           charArrStringS[removables[i]] = s[removables[i]];
        }
        
        return false;
    }
    
    int maximumRemovals(string s, string p, vector<int>& removable) 
    {
        vector<char> charArrStringS(s.length());
        for (int i = 0; i < charArrStringS.size(); i++) 
        {
            charArrStringS[i] = s[i];
        }
        
        int start = 0, end = removable.size() - 1;
        int maxRemovals = -1;
        
        while (start <= end) 
        {
            int possibleK = start + (end - start) / 2;
            if (isValid(s, p, removable, possibleK, charArrStringS)) 
            {
                maxRemovals = possibleK;
                start = possibleK + 1;
            } 
            else 
            {
                end = possibleK - 1;
            }
        }
        
        return maxRemovals+1;
    }    
};