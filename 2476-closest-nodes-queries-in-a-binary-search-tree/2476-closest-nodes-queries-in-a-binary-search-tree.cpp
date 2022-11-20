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
    
    void inorder(TreeNode* root, vector<int>& tree)
     {
        if(root)
        {
            inorder(root->left, tree);
            tree.push_back(root->val);
            inorder(root->right, tree);
        }
     }
    
    int upper(vector<int>& v, int n, int x)
    {
        if(x < v[0])
        return -1;
        
       int i=0, j=n-1;
       int ans=-1;
       while(i<=j)
       {
           int mid = i + (j-i)/2;
           if(v[mid] == x)
               return v[mid];
         
           else if(v[mid] < x)
           {
               ans = mid;
               i = mid+1;
           }
           
           else
           j = mid-1;
       }
       
       return v[ans];
    }
    
    int lower(vector<int>& v, int n, int x)
    {
        if(x > v[n-1])
        return -1;
        
       int i=0, j=n-1;
       int ans=-1;
       while(i<=j)
       {
           int mid = i + (j-i)/2;
           if(v[mid] == x)
               return v[mid];
           
           else if(v[mid] > x)
           {
               ans = mid;
               j = mid-1;
           }
           
           else
           i = mid+1;
       }
       
       return v[ans];
    }
    
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) 
    {
        vector<int> tree;
        
        inorder(root, tree);

        for(int i=0; i<tree.size(); i++)
        {
            cout << tree[i] << " ";
        }
        
        vector<vector<int>> ans;
        for(int i=0; i<queries.size(); i++)
        {
            int p = upper(tree, tree.size(), queries[i]);
            int q = lower(tree, tree.size(), queries[i]);
            //cout << p << " " << q << endl;
            ans.push_back({p, q});
        }      
        
        return ans;
    }
};
