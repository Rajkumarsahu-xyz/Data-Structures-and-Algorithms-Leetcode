//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string S)
    {
        stack<char> stk, stk2;
        stk.push(S[0]);
        
        long long ans = 0;
        for(int i=1; i<S.length(); i++)
        {
            if(X >= Y)
            {
                if(!stk.empty() && stk.top() == 'p'  &&  S[i] == 'r')
                {
                    stk.pop();
                    ans += X; 
                }
                
                else
                {
                    stk.push(S[i]);
                }
            }
            
            else
            {
                if(!stk.empty() && stk.top() == 'r'  &&  S[i] == 'p')
                {
                    stk.pop();
                    ans += Y; 
                }
                
                else
                {
                    stk.push(S[i]);
                }
            }
        }
        
        if(stk.size() > 1)
        {
            stk2.push(stk.top());
            stk.pop();
            // cout << stk.size() << " " << stk2.size() << endl;
            while(stk.size() > 0)
            {
                if(X >= Y)
                {
                    if(!stk2.empty() && stk.top() == 'r'  &&  stk2.top() == 'p')
                    {
                        stk.pop();
                        stk2.pop();
                        ans += Y;
                    }
                    else
                    {
                        stk2.push(stk.top());
                        stk.pop();
                    }
                }
                
                else
                {
                    if(!stk2.empty() && stk.top() == 'p'  &&  stk2.top() == 'r')
                    {
                        // cout << ans << endl;
                        stk.pop();
                        stk2.pop();
                        ans += X;
                    }
                    else
                    {
                        stk2.push(stk.top());
                        stk.pop();
                    }
                }
            }
        }
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends