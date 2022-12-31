class Solution {
public:
    int isvalid(vector<int>& bloomDay, int day, int k)
    {
        int ans=0, ctr=0;
        for(int i=0; i<bloomDay.size(); i++)
        {
            if(bloomDay[i] <= day)
                ctr++;
            else
                ctr=0;
            if(ctr==k)
            {
                ans++;
                ctr=0;
            }
        }
        
        return ans;
    }
    
    
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        auto p = minmax_element(bloomDay.begin(), bloomDay.end());
        int j=*p.second,i=*p.first;
        int mid;
        while(i<j)				
        {
            mid=(i+j)>>1;
            if(isvalid(bloomDay,mid,k)<m)
                i=mid+1;
            else
                j=mid;
        }
        return isvalid(bloomDay,i,k)>=m ? i : -1;
    }
};