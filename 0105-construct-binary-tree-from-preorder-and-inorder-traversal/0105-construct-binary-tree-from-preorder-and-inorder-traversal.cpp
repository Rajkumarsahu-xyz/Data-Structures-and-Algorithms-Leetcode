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
    TreeNode* build(vector<int>& inorder, int instart, int inend, vector<int>& preorder, int prestart, int preend, unordered_map<int, int>& mp) 
    {
        if(instart > inend  ||  prestart > preend)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[prestart]);
        int rootind = mp[root->val];
        int leftchilds = rootind - instart;
        
        root->left = build(inorder, instart, rootind-1, preorder, prestart+1, prestart+leftchilds, mp);
        root->right = build(inorder, rootind+1, inend, preorder, prestart+leftchilds+1, preend, mp);
        
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        unordered_map<int, int> mp;
        for(int i=0; i<inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        
        return build(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1, mp);
    }
};