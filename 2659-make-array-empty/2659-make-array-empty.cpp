class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& A) 
    {
//         list<int> l;
//         int n = nums.size();
//         for(int i=0; i<n; i++)
//         {
//             l.push_back(nums[i]);
//         }
        
//         sort(nums.begin(), nums.end());
//         int i = 0;
//         int ctr = 0;
//         while(!l.empty())
//         {
//             if(l.front() == nums[i])
//             {
//                 ctr++;
//                 l.pop_front();
//             }
            
//             else
//             {
//                 while(l.front() != nums[i])
//                 {
//                     int k = l.front();
//                     l.pop_front();
//                     l.push_back(k);
//                     ctr++;
//                 }
//                 l.pop_front();
//                 ctr++;
//             }
//             i++;
//         }
        
//         return ctr;
        
            unordered_map<int, int> pos;
            long long n = A.size(), res = n;
            for (int i = 0; i < n; ++i)
                pos[A[i]] = i;
            sort(A.begin(), A.end());
            for (int i = 1; i < n; ++i)
                if (pos[A[i]] < pos[A[i - 1]])
                    res += n - i;
            return res;       
        
    }
};