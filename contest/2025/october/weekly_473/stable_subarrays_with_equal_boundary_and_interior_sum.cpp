class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        map<long long, map<int, int>> mpp; mpp[0][capacity[0]] = 1;
        long long sum = 0, ans = 0, n = capacity.size();
        for(int i = 1; i < n - 1; i++) {
            sum += capacity[i];
            long long x = capacity[i+1];
            long long req = sum - x;
            if(mpp.find(req) != mpp.end() && mpp[req].find(x) != mpp[req].end()) ans += mpp[req][x];
            mpp[sum][capacity[i]]++;
        }
        return ans;
    }
};