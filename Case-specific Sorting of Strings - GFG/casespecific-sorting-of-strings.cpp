//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string &str, int n)
    {
       vector<int> v(123,0);
       for(auto &x: str)v[x]++;
       int j=65,k=97;
       for(int i=0;i<n;i++)
       {
           if(str[i]<97)
           {
               while(!v[j])j++;
               v[str[i]=j]--;
           }
           else
           {
               while(!v[k])k++;
               v[str[i]=k]--;
           }
       }
       return str;
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends