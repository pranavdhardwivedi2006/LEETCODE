class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> trk(value, 0);
        for(auto& it : nums) {
            if(it < 0) trk[(value - abs(it) % value) % value]++;
            else trk[it % value]++;
        }
        int ans = 0; while (trk[ans % value]--) ans++;
        return ans;
    }
};