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
    int pathsum(TreeNode *root, int& mx)
    {
        if(root == NULL)
            return 0;
        
        int left = max(0, pathsum(root->left, mx));
        int right = max(0, pathsum(root->right, mx));
        
        mx = max(mx, root->val+left+right);
        return root->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root)
    {
        int mx = INT_MIN;
        int ans = pathsum(root, mx);
        return mx;
    }
};