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
    TreeNode* findExtremeRight(TreeNode* root) 
    {
        if (root->right == NULL) 
            return root;
        
        return findExtremeRight(root->right);
    }
    
    TreeNode* deleted(TreeNode* root, int val)
    {
        if (root->left == NULL) 
        {
            return root->right;
        } 
        else if (root->right == NULL)
        {
            return root->left;
        } 
        
        TreeNode* extremeRight = findExtremeRight(root->left);
        extremeRight->right = root->right;
        
        return root->left; 
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root == NULL)
            return root;
        if(root->val == key)
        {
           return deleted(root, key);
        }
        
        TreeNode *t = root;
        while (t != NULL) 
        {
            if (t->val > key) 
            {
                if (t->left != NULL && t->left->val == key) 
                {
                    t->left = deleted(t->left, key);
                    break;
                } 
                else 
                {
                    t = t->left;
                }
            } 
            else 
            {
                if (t->right != NULL && t->right->val == key) 
                {
                    t->right = deleted(t->right, key);
                    break;
                } 
                else 
                {
                    t = t->right;
                }
            }
        }
        
        return root;
    }
};