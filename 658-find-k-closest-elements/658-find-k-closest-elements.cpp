class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        if(arr.size() == k)
            return arr;
        vector<pair<int,int>> v(arr.size());
        for(int i=0; i<arr.size(); i++)
        {
            v[i].first = (abs(arr[i]-x));
            v[i].second = arr[i];
        }
        
        sort(v.begin(), v.end());
        vector<int> ans;
        for(int i=0; i<k; i++)
        {
            //cout << v[1] << " " ;
            ans.push_back(v[i].second);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};