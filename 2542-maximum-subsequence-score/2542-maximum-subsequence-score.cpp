// #define ll long long int
// class Solution {
// public:
//     static bool cmp(pair<int, int>& a, pair<int, int>& b)
//     {
//         if(a.second==b.second)
//             return a.first > b.first;
//         return a.second > b.second;
//     }
    
//     long long maxScore(vector<int>& nums1, vector<int>& nums2, int k)
//     {
//         vector<pair<int, int>> pr;
//         int n = nums1.size();
//         ll ans = 0;
//         for(int i=0; i<nums1.size(); i++)
//         {
//             pr.push_back({nums1[i], nums2[i]});
//         }
        
//         sort(pr.begin(), pr.end(), comp);
//         for(int i=0; i<n; i++)
//         {
//             cout << pr[i].first << " " << pr[i].second << endl;
//         }
//         if(k==1 || k==n)
//         {
//             if(k==1)
//                 return pr[0].second*pr[0].first;
//             else if(k==n)
//             {
//                 ll mn = LLONG_MAX;
//                 ll sum = 0;
//                 for(int i=0; i<n; i++)
//                 {
//                     ll k = pr[i].second;
//                     mn = min(mn, k);
//                     sum += pr[i].first;
//                 }
//                 return mn*sum;
//             }
//         }
        
//             ll mn = LLONG_MAX;
//             ll sum = 0;
//             for(int i=n-k-1; i<n; i++)
//             {
//                 ll k = pr[i].second;
//                 mn = min(mn, k);
//                 sum += pr[i].first;
//             }
//             ans = mn*sum;
//         return mn*sum;
//     }
// };




class Solution {
    public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
       vector<pair<int, int>> p ;
        
        for(int i = 0 ; i<nums1.size() ; i++)
        {
            p.push_back({nums2[i] , nums1[i]});
        }
        
        sort(p.rbegin() , p.rend());
        
        long long ans  = 0;
        long long sum  = 0;
        priority_queue<int> pq;
        for(int i = 0 ; i<k-1 ; i++)
        {
            sum += p[i].second;
            pq.push(-p[i].second);
        }

        for(int i = k-1 ; i<nums1.size() ; i++)
        {

            sum += p[i].second;
            pq.push(-p[i].second);
            
            ans = max(ans, sum * p[i].first );

            sum += pq.top();
            pq.pop();
        }
        
        return ans;
        
        
    }
};