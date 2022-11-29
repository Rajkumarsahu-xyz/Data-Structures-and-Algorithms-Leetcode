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
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector<vector<int>> tree;
        if(root == NULL) return tree;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            vector<int> level;
            
            for(int i=1; i<=n; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                if(temp != NULL)
                {
                    level.push_back(temp->val);
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
            
            if(level.size() > 0)
                tree.push_back(level);
        }
        
        reverse(tree.begin(), tree.end());
        return tree;
    }
};