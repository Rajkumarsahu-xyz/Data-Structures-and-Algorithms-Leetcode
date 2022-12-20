class Solution {
public:
    vector<int> leftmax(vector<long long>& arr, int n)
    {
        stack<pair<long long, int>> stk;
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


    vector<int> rightmax(vector<long long>& arr, int n)
    {
        stack<pair<long long, int>> stk;
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


    long long getMaxArea(vector<long long>& arr, int n)
    {
        vector<int> left = leftmax(arr, n);
        vector<int> right = rightmax(arr, n);

        long long mx = 0;
        for(int i=0; i<n; i++)
        {
            long long x = (right[i]-left[i]-1) * arr[i];
            mx = max(mx, x);
        }
        return mx;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<long long> v;
        for(int j=0; j<m; j++)
        {
            v.push_back(matrix[0][j]-48);
        }

        long long mx = getMaxArea(v, m);
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j] == '0')
                {
                    v[j] = 0;
                }

                else
                {
                    v[j] += (matrix[i][j]-48);
                }
            }

            mx = max(mx, getMaxArea(v, m));
        }

        return mx;
    }
};