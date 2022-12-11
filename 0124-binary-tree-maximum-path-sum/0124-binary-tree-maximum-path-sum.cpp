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
    int gainFromSubtree(TreeNode* root, int &maxSum) 
    {
        if (root == NULL)
            return 0;

        int gainFromLeft = max(gainFromSubtree(root->left, maxSum), 0);
        int gainFromRight = max(gainFromSubtree(root->right, maxSum), 0);
        maxSum = max(maxSum, gainFromLeft+gainFromRight+root->val);

        return max(gainFromLeft+root->val, gainFromRight+root->val);
    }
    
    int maxPathSum(TreeNode* root) 
    {
        int maxSum = INT_MIN;
        gainFromSubtree(root, maxSum);
        return maxSum;
    }
};