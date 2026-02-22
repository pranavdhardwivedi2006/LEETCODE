class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int first = 0, second = 0, n = nums.size();
        bool turn = true;
        for(int i = 0; i < n; i++) {
            if(nums[i] & 1) turn = !turn;
            if((i + 1) % 6 == 0) turn = !turn;
            if(turn) first += nums[i];
            else second += nums[i];
        }
        return first - second;
    }
};