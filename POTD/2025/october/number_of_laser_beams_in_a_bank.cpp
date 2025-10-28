
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int sum = 0, curr = 0, ans = 0; 
        for(auto it : nums) sum += it;
        for(auto it : nums) {
            if(it == 0) {
                int k = abs(sum - 2 * curr);
                if(k == 0) ans += 2;
                if(k == 1) ans += 1;
            }
            else curr += it;
        }
        return ans;
    }
};