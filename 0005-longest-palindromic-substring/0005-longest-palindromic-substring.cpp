class Solution {
public:
    string longestPalindrome(string s) {
        string t="_";
        for (char c: s){
            t.push_back(c);
            t.push_back('_');
        }

        int n=t.size();
        vector<int> pRad(n, 0);
        int c=0, radius=0;
        #pragma unroll
        for(int i=0; i<n; i++){
            int reflex=2*c-i;
            if (i<radius) pRad[i]=min(radius-i, pRad[reflex]);
            while(i+1+pRad[i]<n && i-1-pRad[i]>=0 &&
                t[i+1+pRad[i]]==t[i-1-pRad[i]])
                    pRad[i]++;
            if (i+pRad[i]>radius){
                c=i;
                radius=i+pRad[i];
            }
        }

        int maxLen=0, cIdx=0;
        #pragma unroll
        for(int i=0; i<n; i++)
            if (pRad[i]>maxLen){
                maxLen=pRad[i];
                cIdx=i;
            }
        
        int l=(cIdx-maxLen)/2;
        return s.substr(l, maxLen);
    }
};