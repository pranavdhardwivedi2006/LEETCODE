class Solution {
private:
    int calc(long long x, vector<int>& arr, long long prod) {
        int n = arr.size();
        int l = 0, r = n - 1, ans = 0;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(x * arr[mid] >= prod) {
                ans = max(ans, n - mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size(); vector<int> ans(n);
        for(int i = 0; i < n; i++) ans[i] = calc(spells[i], potions, success);
        return ans;
    }
};