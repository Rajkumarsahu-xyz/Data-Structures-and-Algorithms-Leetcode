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
    
    bool isSym(TreeNode* l, TreeNode* r)
    {
        if(!l && !r)
            return true;
        else if((!l && r)  ||  (l && !r))
            return false;
        
        return (l->val==r->val) && isSym(l->left, r->right) && isSym(l->right, r->left);
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        if(!root)
            return true;
        else
            return isSym(root->left, root->right);
    }
};