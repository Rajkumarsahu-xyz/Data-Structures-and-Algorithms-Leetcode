class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) 
    {
        int base = (floor(minutesToTest/minutesToDie) + 1);
        return ceil(log2(buckets)/log2(base));
    }
};