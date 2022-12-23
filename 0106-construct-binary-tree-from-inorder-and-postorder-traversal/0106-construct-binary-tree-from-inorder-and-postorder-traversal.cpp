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
    
    TreeNode* build(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int poststart, int postend, unordered_map<int, int>& mp) 
    {
        if(instart > inend  ||  poststart > postend)
            return NULL;
        
        TreeNode* root = new TreeNode(postorder[postend]);
        int rootind = mp[root->val];
        int leftchilds = rootind - instart;
        
        root->left = build(inorder, instart, rootind-1, postorder, poststart, poststart+leftchilds-1, mp);
        root->right = build(inorder, rootind+1, inend, postorder, poststart+leftchilds, postend-1, mp);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        unordered_map<int, int> mp;
        for(int i=0; i<inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mp);
    }
};