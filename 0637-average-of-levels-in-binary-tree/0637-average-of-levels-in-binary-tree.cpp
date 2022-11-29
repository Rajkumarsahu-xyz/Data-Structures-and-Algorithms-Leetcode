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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> tree;
        
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
                    if(temp->left) q.push(temp->left);
                    if(temp->right) q.push(temp->right);
                }
            }
            
            double sum = 0;
            for(int i=0; i<level.size(); i++)
            {
                sum += level[i];
            }
            
            if(level.size() > 0)
                tree.push_back(sum/level.size());
        }
        
        return tree;
    }
};