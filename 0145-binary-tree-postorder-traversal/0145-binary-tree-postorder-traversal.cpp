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
class Solution 
{
    
// public:
//     vector<int> postorderTraversal(TreeNode* root) 
//     {
//         vector<int> posttree;
//         postorder(root, posttree);
//         return posttree;
//     }
    
// private:
//     void postorder(TreeNode* root, vector<int>& posttree)
//     {
//         if(root == NULL) return;
        
//         postorder(root->left, posttree);
//         postorder(root->right, posttree);
//         posttree.push_back(root->val);
//     }
    
    
    public:
        vector<int> postorderTraversal(TreeNode* root) 
        {
            vector<int> posttree;
            if (!root) 
                return posttree;
    
            stack<TreeNode*> s1, s2;
            s1.push(root);
            while(!s1.empty()) 
            {
                TreeNode* t = s1.top();
                s1.pop();
                s2.push(t);
                if (t->left) s1.push(t->left);
                if (t->right) s1.push(t->right);
            }
            
            while(!s2.empty())
            {
                posttree.push_back(s2.top()->val);
                s2.pop();
            }
            return posttree;
        }
    
};