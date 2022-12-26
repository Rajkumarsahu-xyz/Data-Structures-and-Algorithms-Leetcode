/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root)
    {
        long long ans = LLONG_MIN;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            long long mn_ind = q.front().second;
            int n = q.size();
            long long l, r;
            for(int i=0; i<n; i++)
            {
                long long index = q.front().second - mn_ind;
                TreeNode* t = q.front().first;
                q.pop();
                if (i==0) 
                    l = index;
                if (i==n-1) 
                    r = index;
                
                if (t->left)
                    q.push({t->left, index*2+1});
                if(t->right)
                    q.push({t->right, index*2+2});
            }
            ans = max(ans, r-l+1);
        }
        
        return ans;
    }
};