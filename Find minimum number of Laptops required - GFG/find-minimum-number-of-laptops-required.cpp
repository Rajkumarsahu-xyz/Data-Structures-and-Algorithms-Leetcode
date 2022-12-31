//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    static bool comp(pair<int, int>& a, pair<int, int>& b)
    {
        if(a.second == b.second) return a.first <= b.first;
        return a.second < b.second;
    }
  
    int minLaptops(int N, int start[], int end[]) 
    {
        vector<pair<int, int>> jobs1, jobs2;
        for(int i=0; i<N; i++)
        {
            jobs1.push_back({start[i], end[i]});
        }
        
        jobs2 = jobs1;
        sort(jobs1.begin(), jobs1.end());
        sort(jobs2.begin(), jobs2.end(), comp);
        
        // for(auto x : jobs1)
        // {
        //     cout << x.first << " " << x.second << endl;
        // }
        
        // for(auto x : jobs2)
        // {
        //     cout << x.first << " " << x.second << endl;
        // }
        
        int ctr = 1;
        for(int i=0, j=1; i<jobs2.size() && j<jobs1.size(); )
        {
            //cout << jobs[i] << " " << jobs
            if(jobs1[j].first < jobs2[i].second)
            {
                ctr++;
            }
            
            else
            {
                i++;
            }
            
            j++;
        }
        
        return ctr;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends