class Solution {
public:
    
    bool valid(vector<int> &A, int M, int m) 
    {
        int prev = 0;
        for (int i = 1, j = 1; i < m; i++) 
        {
            
            while (j < A.size() && A[j] < A[prev] + M) 
                j++;
            if (j >= A.size())
                return false;
            prev = j;
        }
        return true;
    }

    int maxDistance(vector<int>& position, int m) 
    {
        sort(position.begin(), position.end());
        if (m == 2) 
            return position.back()-position[0];
        
        int i = 1, j = position.back()-position[0];
        while (i <= j)
        {
            int mid = i + (j-i)/2;
            if (valid(position, mid, m))
                i = mid + 1;
            else 
                j = mid - 1;
        }
        return j;
    }
};