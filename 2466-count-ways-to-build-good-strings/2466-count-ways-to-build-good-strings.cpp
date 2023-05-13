class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) 
    {
        vector<long long int> good(300000);
        good[0] = 1;
        for(int l=0; l<100005; l++)
        {
            good[l+zero] %= 1000000007;
            good[l+zero] += good[l];
             good[l+one] %= 1000000007;
           good[l+one] += good[l];
        }
        
        long long ctr = 0;
        for(int x = low; x<=high; x++)
        {
            ctr = (ctr + good[x])%1000000007;
        }
        return ctr;
    }
};