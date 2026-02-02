class Solution {
private:
    int find(vector<int>& nums, int x) {
        int op = 0;
        for(auto& it : nums) {
            op += it / x;
            if(it % x) op++;
        }
        return op;
    }
public:
    int minimumK(vector<int>& nums) {
        int l = 1, r = 1e6;
        while(l <= r) {
            int mid = (l + r) / 2;
            int op = find(nums, mid);
            if(op <= 1LL * mid * mid) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};