//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

class Shop
{
    vector<int> chocolates;
    int countOfCalls;
    public:
    Shop()
    {
        countOfCalls = 0;
    }
    void addChocolate(int x)
    {
        chocolates.push_back(x);
    }
    long long get(int i)
    {
        countOfCalls++;
        if(i<0 || i>=(int)chocolates.size() || countOfCalls>50)return -1;
        return chocolates[i];
    }
};


// } Driver Code Ends
//User function Template for Java

/*
Instructions - 

    1. 'shop' is object of class Shop.
    2. User 'shop.get(int i)' to enquire about the price
            of the i^th chocolate.
    3. Every chocolate in shop is arranged in increasing order
            i.e. shop.get(i) <= shop.get(i + 1) for all 0 <= i < n - 1
*/
class Solution{
public:
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    long long find(int n, long k)
    {
        int start = shop.get(0);
        if(k < start)
            return 0;
        int ctr = 1;
        long long ans = 0;
        vector<int> price(n, -1);
        price[0] = start;
        while(k>=start)
        {
            int i=0, j=n-1;
            int m = -1;
            // int ctr = 1;
            while(i<=j)
            {
                int mid = i + (j-i)/2;
                int curr;
                if(price[mid] != -1)
                    curr = price[mid];
                else
                {
                    curr = shop.get(mid);
                    price[mid] = curr;
                    ctr++;
                }
                // if(ctr == 50)
                // {
                    
                // }
                if(curr == k)
                {
                    m = curr;
                    break;
                }
                else if(curr < k)
                {
                    m = curr;
                    i = mid+1;
                }
                else
                {
                    j = mid-1;
                }
            }
            
            if(m != -1)
            {
                ans += (k/m);
            }
            k %= m;
        }
        
        // cout << ctr << endl;
        return ans;
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        long long k;
        cin >> k;
        
        Shop shop;
        for(int i = 0; i<n; i++)
        {
            int x;
            cin >> x;
            shop.addChocolate(x);
        }
        
        Solution obj(shop);
        long long res = obj.find(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends