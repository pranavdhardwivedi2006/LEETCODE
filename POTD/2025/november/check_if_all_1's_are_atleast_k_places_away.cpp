class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int dist = 1e6;
        for(auto& it : nums) {
            if(it == 1) {
                if(dist < k) return false;
                dist = 0;
            }
            else dist++;
        }
        return true;
    }
};