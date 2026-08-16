class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxi = *max_element(lights.begin(), lights.end());
        int ans = 0;
        for(auto it : arrivalTime) {
            int k = it % period;
            if(k >= maxi) ans = max(ans, period - k);
        }
        return ans;
    }
};