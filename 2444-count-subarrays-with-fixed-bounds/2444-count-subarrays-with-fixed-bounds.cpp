class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) 
    {
        long res = 0;
        int minFound = 0, maxFound = 0;
        int start = 0, minStart = 0, maxStart = 0;
        
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] < minK || nums[i] > maxK) 
            {
                minFound = 0;
                maxFound = 0;
                start = i+1;
            }
            
            if (nums[i] == minK) 
            {
                minFound = 1;
                minStart = i;
            }
            
            if (nums[i] == maxK) 
            {
                maxFound = 1;
                maxStart = i;
            }
            
            if (minFound && maxFound) 
            {
                res += (min(minStart - start, maxStart - start) + 1);
            }
            
        }
        
        return res;
    }
};





// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int minK, int maxK) 
//     {
//         int k = 2;
        
//         int l=0, r=0;
//         int ctr = 0;
//         for(int i=0; i<nums.size(); i++)
//         {
//             if(k == 0  &&  l!=-1  &&  r!=-1)
//             {
//                 ctr++;
//             }
//             if(nums[i]<minK || nums[i]>maxK)
//             {
//                 k = 2;
//                 l = -1;
//                 r = -1;
//             }
//             if(nums[i] == minK)
//             {
//                 l = i;
//                 k--;
//             }
            
//             if(nums[i] == maxK)
//             {
//                 r = i;
//                 k--;
//             }
            
//         }
        
//         return ctr;
//     }
// };