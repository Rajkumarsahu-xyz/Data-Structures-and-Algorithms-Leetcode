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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> tree;
        if(root == NULL)
        return tree;

        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;

        while(!q.empty())
        {
            vector<int> level;
            int count = q.size();

            while(count > 0)
            {
                TreeNode* t = q.front();
                level.push_back(t->val);
                q.pop();

                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);

                count--;
            }

            if(flag == false)
            {
                tree.push_back(level);
            }

            else
            {
                reverse(level.begin(), level.end());
                tree.push_back(level);
            }

            flag = !flag;
        }

        return tree;
    }
};