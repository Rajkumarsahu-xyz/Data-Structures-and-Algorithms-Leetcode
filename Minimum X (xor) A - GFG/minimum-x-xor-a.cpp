//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) 
    {
        int ctr = 0;
        int n = b;
        while(n) 
        {
            ctr += n & 1;
            n >>= 1;
        }
        //cout << ctr << endl;
        n = a;
        int x = 0;
        int k = ctr;
        int j = 31;
        for(int i=31; i>=0; i--)
        {
            //cout << ((1<<i)&n) << " h" << endl;
            if((n & (1 << i)))
            {
                x = ((1<<i) | x);
                //cout << x << endl;
                // if(k==ctr)
                // j = i;
                
                k--;
            }
            if(k==0)
            break;
        }
        //cout << x << endl;
        if(k > 0)
        {
            for(int i=0; i<31; i++)
            {
                if(!(n & (1 << i)))
                {
                    x = (1<<i) | x;
                    k--;
                }
                if(k == 0)
                break;
            }
        }
        
        return x;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends