//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) 
{
    int n = str.length();
    int i=0, j=n-1;
    
    int ctr = 0;
    while(i<j)
    {
        // cout << i << " " << j << endl;
        if(str[i] == str[j])
        {
            char c = str[i];
            while(i<=j  &&  str[i] == str[j] && str[i]==c)
            {
                // cout << i << " " << j << endl;
                i++; j--;
            }
            while(i<=j && str[i-1]==str[i]) i++;
            while(i<=j && str[j+1]==str[j]) j--;
            ctr++;
        }
        
        else
        {
            while(i<=j  &&  str[i] != str[j])
            {
                i++;
            }
            ctr++;
        }
    }
    
    if(i == j)
        return ctr+1;
    return ctr;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends