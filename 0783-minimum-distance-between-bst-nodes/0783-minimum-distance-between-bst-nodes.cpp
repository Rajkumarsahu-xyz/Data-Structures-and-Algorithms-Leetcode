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
    
    void inorder(TreeNode* root, vector<int>& intree)
    {
        if(root)
        {
            inorder(root->left, intree);
            intree.push_back(root->val);
            inorder(root->right, intree);
        }
    }
    
    int minDiffInBST(TreeNode* root) 
    {
        vector<int> intree;
        inorder(root, intree);
        
        int mn = INT_MAX;
        for(int i=0; i<intree.size()-1; i++)
        {
            mn = min(mn, intree[i+1]-intree[i]);
        }
        
        return mn;
    }
};