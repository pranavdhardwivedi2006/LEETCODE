class Solution {
public:
    int minLights(vector<int>& lights) {
        int maxi = 0, n = lights.size();
        vector<array<int, 2>> ranges, merged;
        for(int i = 0; i < n; i++) {
            if(lights[i]) {
                ranges.push_back({max(0, i - lights[i]), min(n - 1, i + lights[i])});
            }
        }
        sort(ranges.begin(), ranges.end());
        if(ranges.empty()) {
            int ans = n / 3;
            if(n % 3) ans++;
            return ans;
        }
        merged.push_back(ranges[0]);
        for(int i = 1; i < ranges.size(); i++) {
            if(merged.back()[1] < ranges[i][0]) merged.push_back(ranges[i]);
            else merged.back()[1] = max(merged.back()[1], ranges[i][1]);
        }
        int ans = 0;
        if(merged[0][0]) {
            ans = merged[0][0] / 3;
            if(merged[0][0] % 3) ans++;
        }
        if(merged.back()[1] < n - 1) {
            int k = n - 1 - merged.back()[1];
            ans += k / 3;
            if(k % 3) ans++;
        }
        for(int i = 1; i < merged.size(); i++) {
            int k = merged[i][0] - merged[i-1][1] - 1;
            ans += k / 3;
            if(k % 3) ans++;
        }
        return ans;
    }
};