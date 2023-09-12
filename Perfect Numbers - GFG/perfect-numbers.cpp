//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        vector<long long> factors;
        factors.push_back(1);
        long long temp = N;
        long long sum = 0;
        
        while (N != 1)
        {
            for (long long i = 2; i <= N; i++)
            {
                if (N % i == 0)
                {
                    long long size = factors.size();
                    for (int j = 0; j < size; j++)
                    {
                        long long ele = factors[j] * i; 
                        if (ele > factors[size - 1])
                            factors.push_back(ele);
                    }
                    
                    N = N/i;
                    break;
                }
            }
        }
        
        
        
        
        long long size = factors.size();
        
        for (long long i = 0; i < size - 1; i++) 
        {
            // cout << factors[i] << " ";
            sum += factors[i];
        }
        // cout << endl;
        
        if (sum == temp)
        {
            return 1;
        }
        else 
        {
            return 0;   
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends