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
    
    vector<string> result;
    void binaryTreePaths(TreeNode* root, vector<string>& result, string t)
    {
        if(!root->left && !root->right) 
        {
            result.push_back(t);
            return;
        }

        if(root->left) binaryTreePaths(root->left, result, t + "->" + to_string(root->left->val));
        if(root->right) binaryTreePaths(root->right, result, t + "->" + to_string(root->right->val));
    }

    vector<string> binaryTreePaths(TreeNode* root) 
    {
        if(!root) 
            return result;
    
        binaryTreePaths(root, result, to_string(root->val));
        return result;
    }
};