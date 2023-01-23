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
    bool symmetricity(TreeNode* l, TreeNode* r)
    {
        if(l && r)
        {   
            return (l->val==r->val) && symmetricity(l->left, r->right) && symmetricity(l->right, r->left);
        }
        if(!l&&r || l&&!r)
            return false;
        else
            return true;
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        if(!root->left && !root->right)
            return root;
        return symmetricity(root->left, root->right);
    }
};