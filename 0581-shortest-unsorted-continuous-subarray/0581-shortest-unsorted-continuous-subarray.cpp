class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {

        int ans = 0;
        int i = 0, j = nums.size()-1;

        int curr_max = INT_MAX;
        int curr_min = INT_MIN;
        int start=0,end=-1;
        
        while(j >= 0)
        {
            if(nums[i] >= curr_min) 
                curr_min = nums[i];
            else 
                end = i;
            
            if(nums[j] <= curr_max) 
                curr_max = nums[j];
            else 
                start = j;

            i++; j--;
        }
        
        return end - start + 1;
    }
};







// class Solution {
// public:
    
//     int qsort2(vector<int> a, int l, int h)
//     {
//         int p = a[h];
//         int i = l-1;
//         for(int j=l; j<=h-1; j++)
//         {
//             if(a[j] <= p)
//             {
//                 i++;
//                 swap(a[i], a[j]);
//             }
//         }
//         swap(a[i+1], a[h]);
//         return i+1;
//     }
    
//     int qsort1(vector<int> a, int l, int h)
//     {
//         int p = a[l];
//         int i = h+1;
//         for(int j=h; j>=l+1; j--)
//         {
//             if(a[j] >= p)
//             {
//                 i--;
//                 swap(a[i], a[j]);
//             }
//         }
//         swap(a[i-1], a[l]);
//         return i-1;
//     }
    
//     int findUnsortedSubarray(vector<int>& nums) 
//     {
//         int n = nums.size();
//         int l=0, h=n-1;
//         int p1=n-1; int p2=0;
//         while(l < n-1)
//         {
//             if(l < n-1 && nums[l] > nums[l+1])
//             {
//                 p1 = min(p1, qsort2(nums, 0, l+1));
//                 p2 = max(p2, qsort1(nums, l, n-1));
//                 //break;
//             }
//             l++;
//         }
        
        
//         while(h > 0)
//         {
//             if(h > 0 && nums[h] < nums[h-1])
//             {
//                 p2 = max(p2, qsort1(nums, h-1, n-1));
//                 p1 = min(p1, qsort2(nums, 0, h));
//                 //break;
//             }
//             h--;
//         }
        
//         if(p1 == n-1  &&  p2 == 0)
//             return 0;
        
//         //cout << p1 << " " << p2 << endl;
//         return p2-p1+1;
//     }
// };