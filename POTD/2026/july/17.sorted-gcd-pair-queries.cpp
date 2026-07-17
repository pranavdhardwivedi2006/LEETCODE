class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> freq(maxi + 1, 0), ans;
        vector<long long> g_cnt(maxi + 1, 0);
        for(auto& it : nums) freq[it]++;
        for(int i = 1; i <= maxi; i++) {
            long long cnt = 0;
            for(int j = i; j <= maxi; j += i) {
                cnt += freq[j];
            }
            g_cnt[i] = cnt * (cnt - 1) / 2;
        }
        for(int i = maxi; i; i--) {
            for(int j = i * 2; j <= maxi; j += i) {
                g_cnt[i] -= g_cnt[j];
            }
        }
        vector<pair<int, long long>> prefix;
        long long prev = 0;
        for(int i = 1; i <= maxi; i++) {
            if(g_cnt[i]) {
                prev += g_cnt[i];
                prefix.push_back({i, prev});
            }
        }
        for(auto it : queries) {
            long long k = it + 1;
            int l = 0, r = prefix.size() - 1;
            while(l <= r) {
                int mid = (l + r) >> 1;
                if(prefix[mid].second >= k) r = mid - 1;
                else l = mid + 1;
            }
            ans.push_back(prefix[l].first);
        }
        return ans;
    }
};