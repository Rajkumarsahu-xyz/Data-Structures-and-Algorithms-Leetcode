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

	void inorder(TreeNode* root, TreeNode* &firstMistake, TreeNode* &secondMistake, TreeNode* &prev) 
    {
		if(root == NULL) 
			return;

		inorder(root->left, firstMistake, secondMistake, prev);

		if(firstMistake == NULL && root->val < prev->val)
			firstMistake = prev;
		if(firstMistake != NULL && root->val < prev->val)
			secondMistake = root;
        
		prev = root;
		inorder(root->right, firstMistake, secondMistake, prev);
	}
    
    
	void recoverTree(TreeNode* root) 
    {
        TreeNode* firstMistake, *secondMistake, *prev;
		prev = new TreeNode(INT_MIN);
        
		inorder(root, firstMistake, secondMistake, prev);
        
		swap(firstMistake->val, secondMistake->val);
	}
};