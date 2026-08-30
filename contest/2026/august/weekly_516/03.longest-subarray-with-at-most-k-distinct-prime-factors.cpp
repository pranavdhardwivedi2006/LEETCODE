class Solution {
void find(vector<int>& prime) {
    prime.resize(1e5 + 1, 0);
    for(int i = 2; i <= 1e5; i++) prime[i] = i;
    for(int i = 2; i * i <= 1e5; i++) {
        if(prime[i] == i) {
            for(int j = i * i; j <= 1e5; j += i) {
                prime[j] = i;
            }
        }
    }
}
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), l = 0, r = 0;
        vector<int> prime; find(prime);
        vector<vector<int>> factors(n);
        for(int i = 0; i < n; i++) {
            int k = nums[i];
            while(k > 1) {
                int p = prime[k];
                factors[i].push_back(p);
                while(k % p == 0) k /= p;
            }
        }
        unordered_map<int, int> mp;
        int ans = 0;
        while(r < n) {
            for(auto it : factors[r]) mp[it]++;
            while(mp.size() > k) {
                for(auto it : factors[l]) {
                    if(mp[it] == 1) mp.erase(it);
                    else mp[it]--;
                }
                l++;
            }
            if(mp.size() <= k) ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};