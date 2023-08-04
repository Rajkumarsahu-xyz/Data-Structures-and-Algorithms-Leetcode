class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int p, int strength) 
    {
        int n = tasks.size(), m = workers.size();
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        
        int lo = 0, hi = min(m, n);
        int ans;
        
        while(lo <= hi) 
        {
            int mid = lo + (hi-lo)/2;
            int ctr = 0;
            int flag = 1;
            
            // Inserting all workers in a multiset
            multiset<int> st(workers.begin(), workers.end());
            
            // Checking if the mid smallest tasks can be assigned
            for(int i = mid - 1; i >= 0; i--) 
            {
                // Case 1: Trying to assing to a worker without the pill
                auto it = prev(st.end());
                if(tasks[i] <= *it) 
                {
                    // Case 1 satisfied!
                    st.erase(it);
                } 
                else 
                {
                    // Case 2: Trying to assign to a worker with the pill
                    auto it = st.lower_bound(tasks[i] - strength);
                    if(it != st.end()) 
                    {
                        // Case 2 satisfied!
                        ctr++;
                        st.erase(it);
                    } 
                    else 
                    {
                        // Case 3: Impossible to assign mid tasks
                        flag = -1;
                        break;
                    }
                }
                
                // If at any moment, the number of pills require for mid tasks exceeds 
                // the allotted number of pills, we stop the loop
                if(ctr > p) 
                {
                    flag = -1;
                    break;
                }
            }
            
            if(flag == 1) 
            {
                ans = mid;
                lo = mid + 1;
            } 
            else
            {
                hi = mid - 1;
            }
        }
        
        return ans;
    }
};