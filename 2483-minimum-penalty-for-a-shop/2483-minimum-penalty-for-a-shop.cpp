// class Solution {
// public:
    
//     bool isfeasible(int mid, string customers, int n, int mn)
//     {
//         int ctr = 0;
//         for(int i=0; i<n; i++)
//         {
//             if(i<mid && customers[i]=='N')
//             {
//                 ctr++;
//             }
//             else if(i>=mid && customers[i]=='Y')
//             {
//                 ctr++;
//             }
//         }
        
//         return (ctr<mn);
//     }
    
//     int bestClosingTime(string customers)
//     {
//         int n = customers.length();
        
//         int i=0, j=n-1;
//         int mn = INT_MAX, ans = INT_MAX;
        
//         while(i<=j)
//         {
//             int mid = i + (j-i)/2;
//             if(isfeasible(mid, customers, n, mn))
//             {
//                 ans = i;
//             }
            
//             else
//         }
//     }
// };











class Solution {
public:
    int bestClosingTime(string customers) {
        // Start with closing at hour 0 and assume the current penalty is 0.
        int minPenalty = 0, curPenalty = 0;
        int earliestHour = 0;

        for (int i = 0; i < customers.size(); i++) {
            char ch = customers[i];
            
            // If status in hour i is 'Y', moving it to open hours decrement
            // penalty by 1. Otherwise, moving 'N' to open hours increment
            // penatly by 1.
            if (ch == 'Y') {
                curPenalty--;
            } else {
                curPenalty++;
            }

            // Update earliestHour if a smaller penatly is encountered.
            if (curPenalty < minPenalty) {
                earliestHour = i + 1;
                minPenalty = curPenalty;
            }
        }

        return earliestHour;
    }
};