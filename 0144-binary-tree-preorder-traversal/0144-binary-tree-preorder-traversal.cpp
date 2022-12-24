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
#include <stack>
class Solution 
{
    
// public:
//     vector<int> preorderTraversal(TreeNode* root) 
//     {
//         vector<int> pretree;
//         preorder(root, pretree);
//         return pretree;
//     }
    
// private:
//     void preorder(TreeNode* root, vector<int>& pretree)
//     {
//         if(root == NULL) return;
        
//         pretree.push_back(root->val);
//         preorder(root->left, pretree);
//         preorder(root->right, pretree); 
//     }
    
    
    public:
        vector<int> preorderTraversal(TreeNode* root) 
        {
            if(!root)
                return {};
            vector<int> preorder;
            stack<TreeNode*> stk;
            stk.push(root);
            while(!stk.empty())
            {
                TreeNode* t = stk.top();
                stk.pop();
                preorder.push_back(t->val);
                
                if(t->right)
                    stk.push(t->right);
                if(t->left)
                    stk.push(t->left);
            }
            
            return preorder;
        }
    
};