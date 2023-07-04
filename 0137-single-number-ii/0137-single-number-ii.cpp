class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int ones = 0, twos = 0;
        // First time number appear -> save it in "ones" 
        // Second time -> clear "ones" but save it in "twos" for later check
        // Third time -> try to save in "ones" but if value saved in "twos" clear it.
        
        for(int i = 0; i < nums.size(); i++)
        {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
};


// Input : [2,2,2,3]
// Stdout:

// 2 0 // 2 is stored in ones
// 0 2 // 2 is cleared from ones and stored in twos
// 0 0 // third time 2 appears it is erased from both ones and twos
// 3 0
// Output:3