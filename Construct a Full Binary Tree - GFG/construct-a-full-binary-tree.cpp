//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* Structre of the Node of the Binary Tree is as follows
struct Node
{
        int data;
        struct Node *left, *right;
};
*/
// your task is to complete this function
// function should create a new binary tree
// function should return the root node to the 
// new binary tree formed
class Solution{
  public:
  Node* solve(int pre[], int preMirror[], int& size, unordered_map<int,int>& m, int& index, int start, int end){
      if(start>end || index>size){
          return NULL;
      }
      if(index==size||start==end){
          Node* temp = new Node(pre[index]);
          index++;
          return temp;
      }
      Node* temp = new Node(pre[index]);
      index++;
      int i = m[pre[index]];
      temp->left = solve(pre, preMirror, size, m, index, i, end);
      temp->right = solve(pre, preMirror, size, m, index, start+1, i-1);
      return temp;
      
  }
    Node* constructBinaryTree(int pre[], int preMirror[], int size)
    {
        // Code here
        unordered_map<int,int> m;
        for(int i=0; i<size; i++){
            m[preMirror[i]]=i;
        }
        int i=0;
        size=size-1;
        return solve(pre, preMirror, size, m, i, 0, size);
    }
};

//{ Driver Code Starts.

void printInorder(Node* node)
{
	if (node == NULL)return;
	printInorder(node->left);
	cout<<node->data<<" ";
	printInorder(node->right);
}

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int preOrder[n];
	    int preOrderMirror[n];
	    for(int i=0; i<n; i++)cin>>preOrder[i];
	    for(int i=0; i<n; i++)cin>>preOrderMirror[i];
	    Solution obj;
	    printInorder(obj.constructBinaryTree(preOrder, preOrderMirror, n));
	    cout<<endl;
    }
	return 0;
}
// } Driver Code Ends