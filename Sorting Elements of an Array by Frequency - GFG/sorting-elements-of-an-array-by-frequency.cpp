#include <iostream>
#include <bits/stdc++.h>
using namespace std;

    static bool comp(pair<int, int>& a, pair<int, int>& b)
    {
        if(a.second == b.second)
            return a.first < b.first;
        
        return a.second > b.second;
    }
    
    vector<int> frequencySort(vector<int>& nums) 
    {
        map<int, int> mp;
        vector<pair<int, int>> pr;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto x : mp)
        {
            pr.push_back({x.first, x.second});
        }
        
        sort(pr.begin(), pr.end(), comp);
        vector<int> ans;
        for(auto x : pr)
        {
            for(int i=0; i<x.second; i++)
            {
                ans.push_back(x.first);
            }
        }
        
        return ans;
    }

int main() 
{
	int T;
	cin >> T;
	while(T--)
	{
	    int n;
	    cin >> n;
	    vector<int> nums(n);
	    for(int i=0; i<n; i++)
	    {
	        int x;
	        cin >> x;
	        nums[i] = x;
	    }
	    
	    vector<int> ans;
	    ans = frequencySort(nums);
	    for(int i=0; i<n; i++)
	    {
	        cout << ans[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}