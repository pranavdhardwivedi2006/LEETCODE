class Solution {
vector<pair<int,int>> temp;
void merge(int st, int mid, int en, vector<pair<int, int>>& arr, vector<int>& cnt) {
    int l = st, r = mid + 1, index = 0;
    while(l <= mid) {
        while(r <= en && arr[l].first >= arr[r].first) {
            temp[index++] = arr[r++];
        }
        cnt[arr[l].second] += en - r + 1;
        temp[index++] = arr[l++];
    }
    while(l <= mid) temp[index++] = arr[l++];
    while(r <= en) temp[index++] = arr[r++];
    for(int i = st; i <= en; i++) arr[i] = temp[i-st];
}
void mergeSort(int l, int r, vector<pair<int, int>>& arr, vector<int>& cnt) {
    if(r <= l) return ;
    int mid = (l + r) >> 1;
    mergeSort(l, mid, arr, cnt);
    mergeSort(mid + 1, r, arr, cnt);
    merge(l, mid, r, arr, cnt);
}
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> prefix(n + 1);
        vector<int> cnt(n + 1, 0); temp.resize(n + 1);
        for(int i = 1; i <= n; i++) {
            prefix[i].first = prefix[i - 1].first + (nums[i - 1] == target ? 1 : -1);
            prefix[i].second = i;
        }
        mergeSort(0, n, prefix, cnt);
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            ans += cnt[i];
        }
        return ans;
    }
};