//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    
    // bool isfeasible(int k, string str, int n)
    // {
    //     int i=0, j=n-k-1;
    //     while(i<j)
    //     {
            
    //     }
    // }

    int addMinChar(string str)
    {    
        int n = str.length();
        // string ans="";
        // if(n==1)
        // return 0;
        // int temp  = 1e5;
        // ans+=str[0];
        // for(int i=1 ;i<n ;i++)
        // {
        //     ans+=str[i];
        //     string res = ans;
        //     reverse(res.begin() ,res.end());
        //   //  cout<<ans<<" "<<res<<endl;
        //     if(res==ans)
        //     {
        //         temp = min(temp,n-i-1);
               
        //     }
        // }
        // if(temp==1e5)
        // return n-1;
        // else
        // return temp;
        
        
        int i=0, j=n-1;
        int f = 0;
        int k = n-1;
        while(i<=j)
        {
            if(str[i] == str[j])
            {
                k = j;
                while(i<=j && str[i] == str[j])
                {
                    i++;
                    j--;
                }
                if(i>j)
                k = n-k-1;
               else
               i=0;
            }
            
            else if(str[i] != str[j])
            {
                i = 0;
                j--;
                k = n-1;
            }
        }
        
        
        return k;
        
        
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends