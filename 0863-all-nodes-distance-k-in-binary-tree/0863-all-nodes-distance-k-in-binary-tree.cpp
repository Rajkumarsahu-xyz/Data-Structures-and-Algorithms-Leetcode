/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parents, TreeNode* target)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        { 
            TreeNode* t = q.front(); 
            q.pop();
            if(t->left)
            {
                parents[t->left] = t;
                q.push(t->left);
            }
            if(t->right)
            {
                parents[t->right] = t;
                q.push(t->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<TreeNode*, TreeNode*> parents;
        markParents(root, parents, target);
        
        unordered_map<TreeNode*, int> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = 1;
        
        int level = 0;
        while(!q.empty())
        { 
            int size = q.size();
            if(level == k) 
                break;
            for(int i=0; i<size; i++)
            {
                TreeNode* t = q.front();
                q.pop();
                if(t->left && visited[t->left]==0) 
                {
                    q.push(t->left);
                    visited[t->left] = 1;
                }
                if(t->right && visited[t->right]==0) 
                {
                    q.push(t->right);
                    visited[t->right] = 1;
                }
                if(parents[t] && visited[parents[t]]==0) 
                {
                    q.push(parents[t]);
                    visited[parents[t]] = 1;
                }
            }
            
            level++;
        }
        
        vector<int> ans;
        while(!q.empty()) 
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};