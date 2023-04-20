//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{
    
public:
    void markParents(Node* root, unordered_map<Node*, Node*> &parents, int home, Node*& tar)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        { 
            Node* t = q.front();
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
            
            if(t->data == home)
            {
                tar = t;
            }
        }
    }
    
    int ladoos(Node* root, int home, int k)
    {
        unordered_map<Node*, Node*> parents;
        Node* tar;
        markParents(root, parents, home, tar);
        
        unordered_map<Node*, int> visited;
        queue<Node*> q;
        q.push(tar);
        int ladoos = tar->data;
        if(k == 0)
            return ladoos;
        visited[tar] = 1;
        
        int burntime = 0;
        // int ladoos = 0;
        while(!q.empty())
        { 
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                Node* t = q.front();
                q.pop();
                if(t->left && visited[t->left]==0) 
                {
                    q.push(t->left);
                    visited[t->left] = 1;
                    ladoos += t->left->data;
                }
                if(t->right && visited[t->right]==0) 
                {
                    q.push(t->right);
                    visited[t->right] = 1;
                    ladoos += t->right->data;
                }
                if(parents[t] && visited[parents[t]]==0) 
                {
                    q.push(parents[t]);
                    visited[parents[t]] = 1;
                    ladoos += parents[t]->data;
                }
            }
            
            burntime++;
            if(burntime == k)
                break;
        }
        return ladoos;
    }


};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends