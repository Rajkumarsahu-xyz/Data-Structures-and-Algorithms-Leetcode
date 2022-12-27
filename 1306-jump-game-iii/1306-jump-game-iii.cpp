class Solution {
public:
    
    bool reach(vector<int>& arr, int i, int n, vector<int>& visited)
    {  
        if(i<0 || i>=n)
            return false;
        
        if(visited[i] == 0)
            return false;
        
        if(arr[i] == 0)
            return true;
        
        visited[i] = 0;
        return reach(arr, i+arr[i], n, visited) || reach(arr, i-arr[i], n, visited);
    }
    
    bool canReach(vector<int>& arr, int start) 
    {
        int n = arr.size();
        vector<int> visited(n, -1);
        return reach(arr, start, n, visited);
    }
};