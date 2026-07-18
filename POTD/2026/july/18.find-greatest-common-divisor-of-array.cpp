class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest = nums[0], largest = nums[0];
        for(auto& it : nums) {
            smallest = min(smallest, it);
            largest = max(largest, it);
        }
        return gcd(smallest, largest);
    }
};