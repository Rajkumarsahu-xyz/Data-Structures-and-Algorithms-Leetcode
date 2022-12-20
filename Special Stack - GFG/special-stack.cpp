//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}
// } Driver Code Ends


stack<int> mnstk;
void push(stack<int>& stk, int a)
{
	stk.push(a);
    if(mnstk.empty() || a <= mnstk.top())
        mnstk.push(a);
}

bool isFull(stack<int>& stk,int n)
{
	return (stk.size() == n);
}

bool isEmpty(stack<int>& stk)
{
    return stk.empty();
}

int pop(stack<int>& stk)
{
	int x = stk.top();
    if(x == mnstk.top())
        mnstk.pop();
    stk.pop();
    return x;
}

int getMin(stack<int>& stk)
{
	return mnstk.top();
}