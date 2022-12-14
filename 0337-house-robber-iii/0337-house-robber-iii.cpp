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
    int robber(TreeNode* root, unordered_map<TreeNode*, int>& mp)
    {
        if(root == NULL)
            return 0;
        if(mp.count(root))
            return mp[root];
        
        int notrobb = robber(root->left, mp) + robber(root->right, mp);
        int robb = root->val;
        if(root->left)
            robb += (robber(root->left->left, mp) + robber(root->left->right, mp));
        if(root->right)
            robb += (robber(root->right->left, mp) + robber(root->right->right, mp));
        
        return mp[root] = max(notrobb, robb);
    }
    
    int rob(TreeNode* root) 
    {
        unordered_map<TreeNode*, int> mp;
        return robber(root, mp);
    }
};