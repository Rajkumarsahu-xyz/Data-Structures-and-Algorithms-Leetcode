class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int i=0, j=letters.size()-1;
        char ans = letters[0];
        while(i<=j)
        {
            int mid = i + (j-i)/2;
            
            if(target+1 == letters[mid])
                return letters[mid];
            
            else if(target < letters[mid])
            {
                if(ans > letters[mid] || ans <= target)
                    ans = letters[mid];
                j = mid-1;
            }
            
            else
                i = mid+1;
        }
        
        return ans;
    }
};