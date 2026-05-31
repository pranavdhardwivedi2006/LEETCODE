class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 40;
        for(auto it : nums) {
            int sum = 0;
            while(it) {
                sum += it % 10;
                it /= 10;
            }
            ans = min(ans, sum);
        }
        return ans;
    }
};