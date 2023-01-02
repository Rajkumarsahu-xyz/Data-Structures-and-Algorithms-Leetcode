//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include <iostream>
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

int key=0;
// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key);

 void insert(struct Node *root,int n1,int n2,char lr)
 {
     if(root==NULL)
        return;
     if(root->key==n1)
     {
         switch(lr)
         {
          case 'L': root->left=new Node(n2);
                    break;
          case 'R': root->right=new Node(n2);
                    break;
         }
     }
     else
     {
         insert(root->left,n1,n2,lr);
         insert(root->right,n1,n2,lr);
     }
 }
// Driver program to test above functions
int main()
{
    /* Let us construct the tree shown in above diagram */
    int t,k;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    struct Node *root=NULL;
    Node *pre=NULL;
    Node *suc=NULL;
    while(n--)
    {
        char lr;
        int n1,n2;
        cin>>n1>>n2;
        cin>>lr;
        if(root==NULL)
        {
            root=new Node(n1);
            switch(lr){
                    case 'L': root->left=new Node(n2);
                    break;
                    case 'R': root->right=new Node(n2);
                    break;
                    }
        }
        else
        {
            insert(root,n1,n2,lr);
        }
    }
   // Inorder(root);
    //Node * target =ptr;
    //printkdistanceNode(root, target, k);
    //cout<<endl;
    cin>>key;
    findPreSuc(root, pre, suc, key);
	if (pre != NULL)
	cout << pre->key;
	else
	cout << "-1";

	if (suc != NULL)
	cout <<" "<<suc->key<<endl;
	else
	cout << " "<<"-1"<<endl;
    }
	return 0;
}
// } Driver Code Ends


/* BST Node
struct Node
{
	int key;
	struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
#include <bits/stdc++.h>
void inorder(Node* root, vector<int>& intree)
{
    if(root == NULL) return;
        
    inorder(root->left, intree);
    intree.push_back(root->key);
    inorder(root->right, intree); 
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    vector<int> intree;
    inorder(root, intree);
    
    // for(int i=0; i<intree.size(); i++)
    // cout << intree[i] << " ";
    // cout << endl;
    
    if(intree[0] > key)
    {
        pre = NULL;
        suc = new Node(intree[0]);
    }
    else if(intree[intree.size()-1] < key)
    {
        pre = new Node(intree[intree.size()-1]);
        suc = NULL;
    }
    
    else
    {
        for(int i=0; i<intree.size(); i++)
        {
            if(intree[i] == key)
            {
                if(i==0)
                pre = NULL;
                else
                pre = new Node(intree[i-1]);
                
                if(i==intree.size()-1)
                suc = NULL;
                else
                suc = new Node(intree[i+1]);
                
                break;
            }
            
            else if(i > 0  && (intree[i-1] < key && intree[i] > key))
            {
                pre = new Node(intree[i-1]);
                suc = new Node(intree[i]);
                
                break;
            }
        }
    }
    
}