class Solution {
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int start = 0, end = n - 1, mid, ans;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            int missed = arr[mid] - (mid+1);
            if (missed >= k)
            {
                ans = arr[mid] - (missed-k+1);
                end = mid - 1;
            }
            if (missed < k)
            {
                start = mid + 1;
                ans = arr[mid] + k - missed;
            }
        }
        return ans;
    }
};