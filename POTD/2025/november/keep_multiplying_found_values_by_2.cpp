class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<bool> trk(maxi + 1, false);
        for(auto it : nums) trk[it] = true;
        while(original <= maxi) {
            if(trk[original]) original *= 2;
            else break;
        }
        return original;
    }
};