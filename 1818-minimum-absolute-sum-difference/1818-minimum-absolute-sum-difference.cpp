class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) 
    {
      long long sum=0;
      vector<int> nums=nums1;
      int n=nums.size();
        
      for(int i=0;i<n;i++) 
          sum += abs(nums1[i]-nums2[i]);
      
      sort(nums.begin(), nums.end());
      long long mnSum=sum;
      
      for(int i=0;i<n;i++) 
      {
            int dist=abs(nums1[i]-nums2[i]);
            int l=0, h=n-1;

            while(l<h) 
            {
                  int m = l + (h-l)/2;
                  if(nums[m]>nums2[i]) 
                      h=m;
                  
                  else
                      l=m+1;
                  
                  dist=min(dist, abs(nums2[i]-nums[m]));
            }

            dist=min(dist, abs(nums2[i]-nums[l]));
            mnSum = min(mnSum, sum - abs(nums1[i]-nums2[i]) + dist);
      }
      
      return mnSum % (1000000007);
    }
};
