//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) 
    {
        vector<int> freq(26, 0);
        int mx = INT_MIN;
        for(int i=0; i<N; i++)
        {
            freq[tasks[i]-'A']++;
            mx = max(mx, freq[tasks[i]-'A']);
        }
        
        int idle_time = (mx-1)*K;
        sort(freq.begin(), freq.end());
        for(int i=0; i<25; i++)
        {
            idle_time -= min(mx-1, freq[i]);
        }
        
        idle_time = max(0, idle_time);
        return idle_time + N;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends