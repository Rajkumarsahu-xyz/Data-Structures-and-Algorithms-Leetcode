//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) 
    {
        unordered_set<int> s;
        vector<int> left(N), right(N);
        
        for(int i=1; i<N; i++)
        {
            s.insert(A[i-1]);
            left[i] = s.size();
        }
        
        s.clear();
        for(int i=N-2; i>=0; i--)
        {
            s.insert(A[i+1]);
            right[i] = s.size();
        }
        
        vector<int> ans;
        for(int i=0; i<N; i++)
        {
            ans.push_back(left[i]-right[i]);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends