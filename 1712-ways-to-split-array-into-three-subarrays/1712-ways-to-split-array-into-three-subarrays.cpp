class Solution {
public:
    int M=1e9+7;
    int waysToSplit(vector<int>& nums) 
    {
        int n=nums.size();
        for(int i=1;i<n;i++)
            nums[i]+=nums[i-1];
        
        int count=0;
        for(int i=0;i<=n-1;i++)
        {
            int lo=i+1,hi=n-2,right=-1,left=-1;
            while(lo<=hi)
            {
                int mid=lo+(hi-lo)/2;
                if(nums[mid]-nums[i]<=nums.back()-nums[mid])
                {
                    right=mid;
                    lo=mid+1;
                }
                else
                    hi=mid-1;
            }
            
            lo=i+1;hi=n-2;
             while(lo<=hi)
            {
                int mid=lo+(hi-lo)/2;
                if(nums[i]<=nums[mid]-nums[i])
                {
                    left=mid;
                    hi=mid-1;
                }
                else
                    lo=mid+1;
            }

            if(left==-1||right==-1||left>right)
                continue;
            
            count=(count+(right-left+1)%M)%M;
        }
        return count%M;
    }
};