//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int groupSize, vector<int> &hand) {
       if (N % groupSize != 0) {
            return false;
        }
        
        map<int, int> cardCount;
        for (int num : hand) {
            cardCount[num]++;
        }
        
        while (!cardCount.empty()) {
            int start = cardCount.begin()->first;
            for (int i = start; i < start + groupSize; i++) {
                if (cardCount.find(i) == cardCount.end()) {
                    return false;
                }
                cardCount[i]--;
                if (cardCount[i] == 0) {
                    cardCount.erase(i);
                }
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends