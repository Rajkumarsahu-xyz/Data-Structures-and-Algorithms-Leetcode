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
    int dia(TreeNode *root, int& mx)
    {
        if(root == NULL)
            return 0;
        
        int left = dia(root->left, mx);
        int right = dia(root->right, mx);
        
        mx = max(mx, left+right);
        return 1 + max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root)
    {
        int mx = INT_MIN;
        int ans = dia(root, mx);
        return mx;
    }
};