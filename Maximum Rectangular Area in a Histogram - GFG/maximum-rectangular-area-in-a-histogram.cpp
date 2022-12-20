//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    vector<int> leftmax(long long arr[], int n)
    {
        stack<pair<long long, int>> stk;
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(stk.size() == 0)
            {
                ans.push_back(-1);
            }

            else if(stk.size()>0  &&  stk.top().first<arr[i])
            {
                ans.push_back(stk.top().second);
            }

            else if(stk.size()>0  &&  stk.top().first>=arr[i])
            {
                while(stk.size()>0  &&  stk.top().first>=arr[i])
                {
                    stk.pop();
                }

                if(stk.size() == 0)
                {
                    ans.push_back(-1);
                }
                else
                {
                    ans.push_back(stk.top().second);
                }
            }

            stk.push({arr[i], i});
        }

        return ans;
    }
    
    
    vector<int> rightmax(long long arr[], int n)
    {
        stack<pair<long long, int>> stk;
        vector<int> ans;
        for(int i=n-1; i>=0; i--)
        {
            if(stk.size() == 0)
            {
                ans.push_back(n);
            }

            else if(stk.size()>0  &&  stk.top().first<arr[i])
            {
                ans.push_back(stk.top().second);
            }

            else if(stk.size()>0  &&  stk.top().first>=arr[i])
            {
                while(stk.size()>0  &&  stk.top().first>=arr[i])
                {
                    stk.pop();
                }

                if(stk.size() == 0)
                {
                    ans.push_back(n);
                }
                else
                {
                    ans.push_back(stk.top().second);
                }
            }
            
            stk.push({arr[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    
    long long getMaxArea(long long arr[], int n)
    {
        vector<int> left = leftmax(arr, n);
        vector<int> right = rightmax(arr, n);
        // for(int i=0; i<n; i++)
        // {
        //     cout << right[i] << " " << left[i] << endl;
        // }
        // cout << endl;
        long long mx = 0;
        for(int i=0; i<n; i++)
        {
            long long x = (right[i]-left[i]-1) * arr[i];
            mx = max(mx, x);
        }
        return mx;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends