class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        vector<int> numcopy = nums;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int l=0, h=n-1;
        int i=0, j=n-1;
        while(i<=j)
        {
            while(i<=j && nums[i] == numcopy[i])
            {
                i++;
            }
            l=i;
            
            while(i<=j && nums[j] == numcopy[j])
            {
                j--;
            }
            h=j;
            break;
        }

        return h-l+1;
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