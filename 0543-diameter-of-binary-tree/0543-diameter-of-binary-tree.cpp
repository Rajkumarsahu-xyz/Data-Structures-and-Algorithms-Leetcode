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
    int dia(TreeNode* root, int &ans)
    {
        if(root)
        {
            int left = dia(root->left, ans);
            int right = dia(root->right, ans);
            
            int h = 1 + max(left, right);
            ans = max(ans, left+right);
            return h;
        }
        return 0;
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int ans = 0;
        int h = dia(root, ans);
        return ans;
    }
};