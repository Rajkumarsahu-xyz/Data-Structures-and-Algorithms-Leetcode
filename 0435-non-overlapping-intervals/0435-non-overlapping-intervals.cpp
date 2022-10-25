bool comp(vector<int> &a,vector<int> &b) 
{
	return a[1]<b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if(intervals.size()==0) 
            return 0;
        sort(intervals.begin(), intervals.end(), comp);
        int count = -1;
        vector<int> prev= intervals[0];
        
        for(vector<int> x: intervals)
        {
            if(prev[1] > x[0]) 
            {
				count++;
			}
            
            else 
            prev = x;
        }
        
        return count;
    }
};