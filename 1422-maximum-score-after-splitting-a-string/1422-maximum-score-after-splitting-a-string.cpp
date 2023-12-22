class Solution {
public:
    int maxScore(string s) 
    {
        int n = s.length();
        vector<int> left(n, 0), right(n, 0);
        
        if(s[0] == '0')
            left[0] = 1;
        if(s[n-1] == '1')
            right[n-1] = 1;
        
        for(int i=1; i<n; i++) {
            if(s[i] == '0') {
                left[i] = left[i-1] + 1;
            }
            else {
                left[i] = left[i-1];
            }
        }
        
        for(int i=n-2; i>=0; i--) {
            if(s[i] == '1') {
                right[i] = right[i+1] + 1;
            }
            else {
                right[i] = right[i+1];
            }
        }
        
        int mx = 0;
        for(int i=0; i<n-1; i++) {
            // cout << left[i] << " " << right[i+1] << endl;
            mx = max(mx, left[i] + right[i+1]);
        }
        
        return mx;
    }
};