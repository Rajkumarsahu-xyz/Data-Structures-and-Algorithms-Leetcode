class Solution {
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int i = 0, j = n - 1, mid, ans;
        while (i <= j)
        {
            mid = i + (j - i) / 2;
            int missed = arr[mid] - (mid+1);
            if (missed >= k)
            {
                ans = arr[mid] - (missed-k+1);
                j = mid - 1;
            }
            if (missed < k)
            {
                i = mid + 1;
                ans = arr[mid] + k - missed;
            }
        }
        return ans;
    }
};