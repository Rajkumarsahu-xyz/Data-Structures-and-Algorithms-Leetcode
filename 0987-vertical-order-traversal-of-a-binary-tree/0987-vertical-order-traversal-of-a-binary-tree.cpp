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
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        map<int, map<int, multiset<int>>> mp;
        q.push({root, {0, 0}});
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0; i<n; i++)
            {
                TreeNode* t = q.front().first;
                int x = q.front().second.first;
                int y = q.front().second.second;
                q.pop();
                mp[x][y].insert(t->val);
                if(t->left)
                    q.push({t->left, {x-1, y+1}});
                if(t->right)
                    q.push({t->right, {x+1, y+1}});
            }
        }
        
        for(auto x : mp)
        {
            vector<int> v;
            for(auto y : x.second)
            {
                v.insert(v.end(), y.second.begin(), y.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};