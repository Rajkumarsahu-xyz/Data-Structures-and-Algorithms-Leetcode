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
    void inorder(TreeNode* root, vector<int> &intree)
    {
        if(root)
        {
            inorder(root->left, intree);
            // cout << root->val << endl;
            intree.push_back(root->val);
            inorder(root->right, intree);
        }
    }
    
    void traverse(TreeNode* root, unordered_map<int, int> mp)
    {
        if(root)
        {
            root->val = mp[root->val];
            traverse(root->left, mp);
            traverse(root->right, mp);
        }
    }
    
    TreeNode* bstToGst(TreeNode* root) 
    {
        vector<int> intree;
        inorder(root, intree);
        
        vector<int> post_sum(intree.size(), 0);
        for(int i=intree.size()-1; i>=0; i--)
        {
            post_sum[i] = intree[i];
            if(i<intree.size()-1)
            {
                post_sum[i] += post_sum[i+1];
            }
        }
        
        unordered_map<int, int> mp;
        for(int i=0; i<intree.size(); i++)
        {
            mp[intree[i]] = post_sum[i];
        }
        
        traverse(root, mp);
        
        return root;
    }
};