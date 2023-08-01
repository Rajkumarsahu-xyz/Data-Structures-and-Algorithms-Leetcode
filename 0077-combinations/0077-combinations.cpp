// class Solution {
// public:
    
//     void combo(vector<int> &nums, int i, int n, vector<int> v, vector<vector<int>> &ans, int k)
//     {
//         if(v.size() == k)
//         {
//             ans.push_back(v);
//             return;
//         }
        
//         v.push_back(nums[i]);
//         combo(nums, i+1, n, v, ans, k);
//         v.pop_back();
//         combo(nums, i+1, n, v, ans, k);
//     }
    
//     vector<vector<int>> combine(int n, int k) 
//     {
//         vector<int> nums;
//         for(int i=1; i<=n; i++)
//         {
//             nums.push_back(i);
//         }
        
//         vector<vector<int>> ans;
//         vector<int> v;
//         combo(nums, 0, n, v, ans, k);
        
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(int idx, int k,vector<int>&current,int n)
    {
        if(current.size()==k)    // base case
        {
            ans.push_back(current);
            return;
        }
        
        for(int i=idx;i<n+1;i++)
        {
            current.push_back(i);  //consider the current element i
            helper(i+1,k,current,n); // generate combinations
            current.pop_back(); //proceed to next element
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>current;
        helper(1,k,current,n);
        return ans; //return answer
    }
};