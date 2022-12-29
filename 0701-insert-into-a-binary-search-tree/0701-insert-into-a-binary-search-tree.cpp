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
    void insert(TreeNode* root, int val)
    {
        while(root != NULL)
        {
            if(val < root->val)
            {
                if(root->left) 
                    root = root->left;
                else
                {
                    root->left = new TreeNode(val);
                    break;
                }
            }
            
            else if(val > root->val)
            {
                if(root->right) 
                    root = root->right;
                else
                {
                    root->right = new TreeNode(val);
                    break;
                }
            }
        }
        
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if(root == NULL)
            return new TreeNode(val);
        insert(root, val);
        return root;
    }
};