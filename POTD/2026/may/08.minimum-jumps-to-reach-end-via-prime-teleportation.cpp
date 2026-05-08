class Solution {
void sieve(vector<int>& prime, int n) {
    prime[1] = 1;
    for(int i = 2; i < n; i++) prime[i] = i;
    for(int i = 2; i < n; i++) {
        if(prime[i] == i) {
            for(long long j = 1LL * i * i; j < n; j += i) {
                if(prime[j] == j) prime[j] = i;
            }
        }
    }
}
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> prime(maxi + 1, 0);
        sieve(prime, maxi + 1);
        unordered_map<int, vector<int>> mpp;
        for(int i = 0; i < n; i++) {
            int temp = nums[i];
            while(temp > 1) {
                int k = prime[temp];
                mpp[k].push_back(i);
                while(temp % k == 0) temp /= k;
            }
        }
        vector<int> dist(n, 1e9);
        queue<int> q;
        q.push(0); dist[0] = 0;
        while(!q.empty()) {
            int idx = q.front(); q.pop();
            int d = dist[idx];
            if(idx == n - 1) return d;
            for(auto it : mpp[nums[idx]]) {
                if(d + 1 < dist[it]) {
                    q.push(it);
                    dist[it] = d + 1;
                }
            }
            mpp[nums[idx]].clear();
            if(idx && d + 1 < dist[idx - 1]) {
                q.push(idx - 1);
                dist[idx - 1] = d + 1;
            }
            if(d + 1 < dist[idx + 1]) {
                q.push(idx + 1);
                dist[idx + 1] = d + 1;
            }
        }
        return -1;
    }
};