//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
        stack<pair<int, int>> stk;
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(stk.size() == 0)
            {
                ans.push_back(1);
            }

            else if(stk.size()>0  &&  stk.top().first>price[i])
            {
                ans.push_back(i - stk.top().second);
            }

            else if(stk.size()>0  &&  stk.top().first<=price[i])
            {
                while(stk.size()>0  &&  stk.top().first<=price[i])
                {
                    stk.pop();
                }

                if(stk.size() == 0)
                {
                    ans.push_back(i+1);
                }
                else
                {
                    ans.push_back(i - stk.top().second);
                }
            }

            stk.push({price[i], i});
        }

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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends