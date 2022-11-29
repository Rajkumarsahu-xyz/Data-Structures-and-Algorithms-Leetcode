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
    int height(TreeNode* node)
    {
        if(node == NULL)
        return 0;
        
        return 1 + max(height(node->left), height(node->right));
    }
    
    bool isBal(TreeNode *root)
    {
        if(root == NULL)
        return true;
        
        int left = height(root->left);
        int right = height(root->right);
        
        return (abs(left-right) <= 1)  &&  isBal(root->left)  &&  isBal(root->right);
    }
    
    bool isBalanced(TreeNode *root)
    {
        return isBal(root);
    }
};