class Solution {
public:
    int partitionDisjoint(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> prefix(n), postfix(n);

        prefix[0] = nums[0];
        for(int i=1; i<n; i++)
            prefix[i] = max(prefix[i-1], nums[i]);
        
        postfix[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--)
            postfix[i] = min(postfix[i+1], nums[i]);
        
        // for(int i=0; i<n; i++)
        //     cout << prefix[i] << " ";
        // cout << endl;
        // for(int i=0; i<n; i++)
        //     cout << postfix[i] << " ";
        // cout << endl;
        
        for(int i=0, j=1; j<n; i++, j++)
        {
            if(prefix[i] <= postfix[j])
                return i+1;
        }
        
        return n-1;
        
    }
};