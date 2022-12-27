/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    string serialize(TreeNode* root) 
    {
        string str = "";
        if(root == NULL) 
            return str;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) 
        {
           TreeNode* t = q.front();
           q.pop();
            
           if(t==NULL) 
               str.append("#,");
           else 
               str.append(to_string(t->val)+',');
            
           if(t != NULL)
           {
               q.push(t->left);
               q.push(t->right);            
           }
        }
        
        return str;
    }

    TreeNode* deserialize(string data) 
    {
        if(data.size() == 0) 
            return NULL; 
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) 
        {  
            TreeNode *node = q.front(); 
            q.pop(); 
            
            getline(s, str, ',');
            if(str == "#")
            {
                node->left = NULL;
            }
            else 
            {
                TreeNode* leftNode = new TreeNode(stoi(str)); 
                node->left = leftNode; 
                q.push(leftNode); 
            }
            
            getline(s, str, ',');
            if(str == "#") 
            {
                node->right = NULL; 
            }
            else 
            {
                TreeNode* rightNode = new TreeNode(stoi(str)); 
                node->right = rightNode;
                q.push(rightNode); 
            }
        }
        return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));