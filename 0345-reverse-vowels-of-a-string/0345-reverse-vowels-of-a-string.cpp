class Solution {
public:
    
    bool ifvowel(char c)
    {
        if(c=='a' || c=='e' || c=='i'|| c=='o' || c=='u'|| c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
            return true;
        return false;
    }
    
    string reverseVowels(string s) 
    {
        for(int i=0, j=s.length()-1; i<j; )
        {
            if(ifvowel(s[i]) && ifvowel(s[j]))
            {
                //cout << s[i] << "1" << s[j] << endl;
                swap(s[i], s[j]);
                i++; j--;
            }
            
            else if(ifvowel(s[i]) && !ifvowel(s[j]))
            {
                //cout << s[i] << "2" << s[j] << endl;
                j--;
            }
            
            else if(!ifvowel(s[i]) && ifvowel(s[j]))
            {
                //cout << s[i] << "3" << s[j] << endl;
                i++;
            }
            
            else
            {
                //cout << s[i] << "4" << s[j] << endl;
                i++; j--;
            }
        }
        
        return s;
    }
};