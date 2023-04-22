//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
private:
    vector<long long> cummulativeSum(vector<int>&arr1,int n){
        vector<long long>ans(n,0);
        ans[0]=arr1[0];
        for(int i=1;i<n;i++){
            ans[i]+=ans[i-1]+arr1[i];
        }
        return ans;
    }
    long long binary_search(vector<int> &arr1,vector<long long> &sum,int target){
        int l,h,m;
        l=0;
        h=arr1.size()-1;
        int index=-1;
        while(l<=h){
            m=l+((h-l)>>1);
            if(arr1[m]>=target){
                index=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        if(index!=-1){
            return sum[index]-target;
        }
        return 0;
    }
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<int>arr1(arr);
        sort(arr1.begin(),arr1.end());
        vector<long long>sum = cummulativeSum(arr1,n); 
        vector<long long>ans(n,0);
        
        for(int i=0;i<n;i++){
            ans[i] =binary_search(arr1,sum,arr[i]);
        }
        return ans;
    }
};
// class Solution{
// public:
//     vector<long long> smallerSum(int n,vector<int> &arr)
//     {
//         sort(arr.begin(), arr.end());
        
//         int sum = 0, s = 0;
//         vector<int> ans;
//         ans.push_back(s);
//         sum += arr[0];
        
//         for(int i=1; i<n; i++)
//         {
            
//         }
        
//     }
// };

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends