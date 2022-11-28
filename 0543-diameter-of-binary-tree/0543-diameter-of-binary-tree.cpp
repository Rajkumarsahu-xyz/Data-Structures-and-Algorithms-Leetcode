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
    
    int dia(TreeNode* root, int &res)
    {
        if(root==NULL)
        return 0;
        
        int left = dia(root->left, res);
        int right = dia(root->right, res);
        
        int temp = 1+max(left,right);
        res = max(res, left+right);
        return temp;
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int res = 0;
        int h = dia(root, res);
        return res;
    }
};