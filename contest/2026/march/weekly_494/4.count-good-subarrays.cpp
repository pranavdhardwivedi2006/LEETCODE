class Solution {
int n;
unordered_map<int, vector<int>> mpp, trk;

void add(int x, int idx) {
    int i = 0;
    while(x) {
        if(x & 1) mpp[i].push_back(idx);
        x >>= 1; i++;
    }
}

int find3(vector<int>& arr, int idx) {
    int l = 0, r = arr.size() - 1, ans = -1;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(arr[mid] >= idx) r = mid - 1;
        else ans = arr[mid], l = mid + 1;
    }
    return ans;
}

pair<int, int> find2(vector<int>& arr, int idx) {
    int l = 0, r = arr.size() - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(arr[mid] <= idx) l = mid + 1;
        else r = mid - 1;
    }
    int x1 = r >= 0 ? arr[r] : -1; 
    l = 0, r = arr.size() - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(arr[mid] >= idx) r = mid - 1;
        else l = mid + 1;
    }
    int x2 = l < arr.size() ? arr[l] : n;
    return {x1, x2};
}

long long find(int idx, int num) {
    int l = 0, r = n - 1;
    for(int i = 0; i < 32; i++) {
        if(num & (1 << i)) continue ;
        auto [u, v] = find2(mpp[i], idx);
        int p = find3(trk[num], idx); u = max(u, p);
        l = max(u + 1, l); r = min(r, v - 1);
    }
    return 1LL * (idx - l + 1) * (r - idx + 1);
}

public:
    long long countGoodSubarrays(vector<int>& nums) {
        n = nums.size(); long long ans = 0; int prev = -1;
        for(int i = 0; i < n; i++) {add(nums[i], i); trk[nums[i]].push_back(i);}
        for(int i = 0; i < n; i++) {
            ans += find(i, nums[i]);
            prev = nums[i];
        }
        return ans;
    }
};