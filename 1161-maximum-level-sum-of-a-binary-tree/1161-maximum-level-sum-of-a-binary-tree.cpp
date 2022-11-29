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
    int maxLevelSum(TreeNode* root) 
    {
        int mxsum = INT_MIN, level=0, mnlevel=0;
        
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;

        while(!q.empty())
        {
            int sum = 0;
            level++;
            int count = q.size();

            while(count > 0)
            {
                TreeNode* t = q.front();
                sum += t->val;
                q.pop();

                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);

                count--;
            }

            if(sum > mxsum)
            {
                mxsum = sum;
                mnlevel = level;
            }
        }

        return mnlevel;
    }
};