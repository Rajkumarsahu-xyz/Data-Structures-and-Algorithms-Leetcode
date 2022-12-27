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
    int leftHeight(TreeNode* root)  
    {
        int lh = 0; 
        while(root) 
        {
            lh++; 
            root = root->left; 
        }
        return lh; 
    }
    
    int rightHeight(TreeNode* root) 
    {
        int rh = 0; 
        while(root) 
        {
            rh++; 
            root = root->right; 
        }
        return rh; 
    }
    
    int countNodes(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        
        int l = leftHeight(root);
        int r = rightHeight(root);
        
        if(l == r)
            return pow(2, l)-1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);    
    }
};