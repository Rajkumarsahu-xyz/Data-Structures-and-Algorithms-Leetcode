//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    
    vector<int> help_classmate(vector<int> arr, int n)
    {
        stack<int> stk;
        vector<int> ans;
        for(int i=n-1; i>=0; i--)
        {
            if(stk.size() == 0)
            {
                ans.push_back(-1);
            }
                
            else if(stk.size()>0  &&  stk.top()<arr[i])
            {
                ans.push_back(stk.top());
            }
                
            else if(stk.size()>0  &&  stk.top()>=arr[i])
            {
                while(stk.size()>0  &&  stk.top()>=arr[i])
                {
                    stk.pop();
                }
                    
                if(stk.size() == 0)
                {
                    ans.push_back(-1);
                }
                else
                {
                    ans.push_back(stk.top());
                }
            }
               
            stk.push(arr[i]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }

};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends