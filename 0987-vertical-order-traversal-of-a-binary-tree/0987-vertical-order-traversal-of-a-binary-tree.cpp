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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        queue<pair<int,TreeNode*> > q;
        vector<vector<int> > ans;
        q.push({0,root});
        map<int,vector<int> > mp;
        mp[0].push_back(root->val);
        
        while(q.size())
        {
            queue<pair<int,TreeNode*> > tq;
            while(q.size())
            {
                TreeNode* node= q.front().second;
                int level=q.front().first;
                if(node->right) tq.push({level+1,node->right});
                if(node->left) tq.push({level-1,node->left});
                q.pop();
            }
            q=tq;
            vector<pair<int,int> > hor_level;
            while(tq.size())
            {
                hor_level.push_back({tq.front().first,tq.front().second->val});
                tq.pop();
            }
            
            sort(hor_level.begin(),hor_level.end());
            for(auto itr:hor_level)
            {
                mp[itr.first].push_back(itr.second);
            }
        }
        
        for(auto itr:mp)
        {
            ans.push_back(itr.second);
        }
        
        return ans;
    }
};