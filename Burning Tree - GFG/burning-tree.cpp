//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    void markParents(Node* root, unordered_map<Node*, Node*> &parents, int target, Node*& tar)
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
            
            if(t->data == target)
            {
                tar = t;
            }
        }
    }


    int minTime(Node* root, int target) 
    {
        unordered_map<Node*, Node*> parents;
        Node* tar;
        markParents(root, parents, target, tar);
        
        unordered_map<Node*, int> visited;
        queue<Node*> q;
        q.push(tar);
        visited[tar] = 1;
        
        int burntime = 0;
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
            
            burntime++;
        }
        return burntime-1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends