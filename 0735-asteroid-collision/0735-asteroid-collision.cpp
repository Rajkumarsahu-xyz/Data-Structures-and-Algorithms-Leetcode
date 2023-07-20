class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteriods) 
    {
        stack<int> stk;
        int n = asteriods.size();
        stk.push(asteriods[0]);
        int i=1;
        while(i<n)
        {
            if(!stk.empty())
            {
                int val = stk.top();
                if(val>0 && asteriods[i]<0)
                {
                    if(val > abs(asteriods[i]))
                    {
                        i++;
                    }
                    else if(val == abs(asteriods[i]))
                    {
                        stk.pop();
                        i++;
                    }
                    else
                    {
                        stk.pop();
                        // stk.push(asteriods[i]);
                    }
                }
                else
                {
                    stk.push(asteriods[i]);
                    i++;
                }
                
            }
            else
            {
                stk.push(asteriods[i]);
                i++;
            }
        }
        
        vector<int> ans;
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};