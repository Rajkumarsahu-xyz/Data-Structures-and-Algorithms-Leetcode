class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        long long sum =0;
        for(int ele : chalk)
        {
            sum = sum + (long long)ele;
        }
        
        k = ((long long)k) % sum;
        int i =0;
        while( i < chalk.size())
        {
            // cout<<k<<" ";
            if(chalk[i] > k) return i;
            k = k - (long long) chalk[i];
            i++;
        }
          return 0;
    }
};