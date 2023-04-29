//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long N){
        // Code here
         long digitPlace = 1; //initialize the digit place variable to 1
        long result = 0; //initialize the result variable to 0
        while (N > 0) { //while n is greater than 0
            N--; //decrement n by 1
            //add the odd digit to the result variable, based on the remainder of n divided by 5
            //multiply it by digitPlace to place it in the correct position
            result += ((2 * (N % 5)) + 1) * digitPlace;
            N = N / 5; //update n by dividing it by 5
            digitPlace *= 10; //update digitPlace by multiplying it by 10
        }
        return result; //return the final value
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends