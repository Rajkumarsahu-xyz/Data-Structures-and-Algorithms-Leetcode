class Solution {
public:
    string breakPalindrome(string palindrome) 
    {
        string p = palindrome;
        int n = palindrome.length();
        
        if(n == 1)
            return "";
        for(int i=0; i<n; i++)
        {
            if(palindrome[i] != 'a'  &&  (n%2 == 0   ||   (n%2 != 0 && i!=(n/2))))
            {
                palindrome[i] = 'a';
                break;
            }
        }
        
        if(palindrome != p)
        return palindrome;
        
        else
        {
            if(palindrome[n-1] == 'a')
                palindrome[n-1] = 'b';
        }
        
        return palindrome;
    }
};