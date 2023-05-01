class Solution {
public:
    double average(vector<int>& salary) 
    {
//         sort(salary.begin(), salary.end());
//         int sum = 0 ;double avg;
//         for(int i=1; i<salary.size()-1; i++)
//         {
//             sum += salary[i];
//         }
        
//         return (sum/(salary.size()-2));
        
        
        int n=salary.size();
        sort(salary.begin(),salary.end());
        int mini = salary[0];
        int maxi = salary[n-1];
        double sum=accumulate(salary.begin(),salary.end(),0);
        // for(int i=0;i<n;i++)
        // {
        // sum+=salary[i];
        // }
        return (sum-(mini+maxi))/(n-2);
    }
};