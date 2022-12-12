class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) 
    {
        int ctr = arr1.size();
        sort(arr2.begin(), arr2.end());
        for(int k=0; k<arr1.size(); k++)
        {
            int p = arr1[k];
            int i=0, j=arr2.size()-1;
            while(i<=j)
            {
                int mid = i + (j-i)/2;
                if(abs(arr2[mid] - p) <= d)
                {
                    ctr--;
                    break;
                }
                else if(arr2[mid] < p)
                    i = mid + 1;
                
                else
                    j = mid - 1;
            }
        }
        
        return ctr;
    }
};