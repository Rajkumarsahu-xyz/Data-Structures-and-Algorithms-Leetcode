class Solution {
    int MOD = 1000000007;
    
    long long power(int x, int n) {
        if( n == 0) return 1;
        
        long long ans = power(x, n / 2);
        ans *= ans;
        ans %= MOD;
        
        if(n % 2 != 0) {
            ans *= x;
            ans %= MOD;
        }
        
        return ans;
    }
    
    long long fact(int n) {
        long long ans = 1;
        
        for(int i = 1; i <= n; i++) {
            ans *= i;
            ans %= MOD;
        }
        
        return ans;
    }
    
    long long nCr(int n, int r) {
        long long ans = fact(n);
        long long denominator = (fact(r) * fact(n - r)) % MOD;
        
        return (ans * power(denominator, MOD - 2)) % MOD;
    }
    
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        priority_queue<int> pq;
        
        vector<int> freq(26);
        for(auto x:s) {
            freq[x - 'a'] += 1;
        }
        
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) pq.push(freq[i]);
        }
        
        if(pq.size() < k) {
            return 0;
        }
        
        long long ans = 1;
        while(k > 0) {
            int countEqual = 0, ele = pq.top();
            while(pq.size() > 0 && pq.top() == ele) {
                countEqual += 1;
                pq.pop();
            }
            
            if(countEqual <= k) {
                k -= countEqual;
                ans *= power(ele, countEqual);
                ans %= MOD;
            } else {
                ans *= power(ele, k);
                ans %= MOD;
                
                ans *= nCr(countEqual, k);
                ans %= MOD;
                break;
            }
        }
        
        return ans;
    }
};