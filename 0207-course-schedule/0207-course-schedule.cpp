class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> adj[numCourses];
        for(auto &x : prerequisites)
        {
            adj[x[1]].push_back(x[0]);
        }
        
        vector<int> ans, indegree(numCourses);
	    queue<int> q;
	    for(int i=0; i<numCourses; i++)
	    {
	        for(auto &x : adj[i])
	        {
	            indegree[x]++;
	        }
	    }
	    
	    for(int i=0; i<numCourses; i++)
	    {
	        if(indegree[i] == 0)
	        {
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto &x : adj[node])
	        {
	            indegree[x]--;
	            if(indegree[x] == 0) q.push(x);
	        }
	    }
	    
	    return (numCourses == ans.size());
    }
};