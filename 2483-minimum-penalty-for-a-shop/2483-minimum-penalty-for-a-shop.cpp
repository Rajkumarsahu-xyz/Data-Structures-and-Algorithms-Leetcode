class Solution {
public:
    int bestClosingTime(string customers) 
    {
        int n = customers.size();
        vector<int> lpre(n+1), rpre(n+1);
        int l=0, r=0;
        
        int i=0, j=n-1; 
        for(; i<n && j>=0; i++, j--)
        {
            lpre[i] = l;
            if(customers[i] == 'N')
                l++;
           
            rpre[j+1] = r;
            if(customers[j] == 'Y')
                r++;
        }
        
        lpre[i] = l;
        rpre[j+1] = r;
        
        int mn = INT_MAX, ans=0;
        for(int i=0; i<n+1; i++)
        {
            if(lpre[i]+rpre[i] < mn)
            {
                mn = lpre[i]+rpre[i];
                ans = i;
            }
        }
        
        return ans;
    }
};