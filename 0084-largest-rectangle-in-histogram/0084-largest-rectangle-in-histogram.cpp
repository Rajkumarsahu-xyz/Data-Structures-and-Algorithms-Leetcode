class Solution {
public:
    vector<int> leftmax(vector<int>& arr, int n)
    {
        stack<pair<int, int>> stk;
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            if(stk.size() == 0)
            {
                ans.push_back(-1);
            }

            else if(stk.size()>0  &&  stk.top().first<arr[i])
            {
                ans.push_back(stk.top().second);
            }

            else if(stk.size()>0  &&  stk.top().first>=arr[i])
            {
                while(stk.size()>0  &&  stk.top().first>=arr[i])
                {
                    stk.pop();
                }

                if(stk.size() == 0)
                {
                    ans.push_back(-1);
                }
                else
                {
                    ans.push_back(stk.top().second);
                }
            }

            stk.push({arr[i], i});
        }

        return ans;
    }


    vector<int> rightmax(vector<int>& arr, int n)
    {
        stack<pair<int, int>> stk;
        vector<int> ans;
        for(int i=n-1; i>=0; i--)
        {
            if(stk.size() == 0)
            {
                ans.push_back(n);
            }

            else if(stk.size()>0  &&  stk.top().first<arr[i])
            {
                ans.push_back(stk.top().second);
            }

            else if(stk.size()>0  &&  stk.top().first>=arr[i])
            {
                while(stk.size()>0  &&  stk.top().first>=arr[i])
                {
                    stk.pop();
                }

                if(stk.size() == 0)
                {
                    ans.push_back(n);
                }
                else
                {
                    ans.push_back(stk.top().second);
                }
            }

            stk.push({arr[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        vector<int> left = leftmax(heights, n);
        vector<int> right = rightmax(heights, n);

        long long mx = 0;
        for(int i=0; i<n; i++)
        {
            long long x = (right[i]-left[i]-1) * heights[i];
            mx = max(mx, x);
        }
        return mx;
    }
};