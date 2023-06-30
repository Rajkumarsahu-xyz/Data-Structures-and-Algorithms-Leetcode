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

class Pair {
    public:
        int H;
        bool B;
    Pair(int h, bool b)
    {
        H = h;
        B = b;
    }
};

class Solution {
public:
    
    Pair checkBalance(TreeNode* root)
    {
        
        if(root==NULL)
        {
            Pair p(0,true);
            return p;
        }
        
        Pair LP = checkBalance(root->left);
        Pair RP = checkBalance(root->right);
        
        int k1 = LP.H;
        int k2 = RP.H;
        int H = max(k1, k2)+1;
        bool bal = (abs(LP.H-RP.H)<=1) && LP.B && RP.B;
        
        Pair ph(H, bal);
        return ph;
    }
    
    
    
    bool isBalanced(TreeNode* root) 
    {
//         if(root==NULL)
//         {
//             Pair p(0,true);
//             return p.B;
//         }
        
//         Pair LP = isBalanced(root->left);
//         Pair RP = isBalanced(root->right);
        
//         int k1 = LP.H;
//         int k2 = RP.H;
//         int H = max(k1, k2)+1;
//         bool bal = (abs(LP.H-RP.H)<=1) && LP.B && RP.B;
        
//         Pair ph(H, bal);
//         return ph.bal;
        
        Pair p = checkBalance(root);
        return p.B;
        
        
    }
};