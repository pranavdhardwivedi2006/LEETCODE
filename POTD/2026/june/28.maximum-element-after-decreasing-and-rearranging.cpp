class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int curr = 0, n = arr.size();
        for(int i = 0; i < n; i++) {
            curr = min(curr + 1, arr[i]);
        }
        return curr;
    }
};