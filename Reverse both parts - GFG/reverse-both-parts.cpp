//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList()
{
    int n; // length of link list
    scanf("%d ", &n);

    int data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i)
    {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
//User function Template for C++

/*
Definition for singly Link List Node
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
*/


class Solution
{
public:
   
    Node *reverse(Node *head, int k)
    {
        Node* prev1 = NULL;
        Node* curr1 = head;
        
        int i = 0;
        while(i < k)
        {
            Node* forward = curr1 -> next;
            
            curr1 -> next = prev1;
            prev1 = curr1;
            curr1 = forward;
            i++;
        }
        
        
        Node* curr2 = curr1;
        Node* prev2 = NULL;
        
        while(curr2 != NULL)
        {
            Node* forward = curr2 -> next;
            
            curr2 -> next = prev2;
            prev2 = curr2;
            curr2 = forward;
        }
        
        Node* temp = prev1;
        
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = prev2;
        
        return prev1;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        struct Node *head = inputList();
        int k;
        cin >> k;

        Solution obj;
        Node *res = obj.reverse(head, k);

        printList(res);
    }
}
// } Driver Code Ends