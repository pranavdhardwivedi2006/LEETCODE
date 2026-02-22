class Solution {
int n;
map<tuple<int, long long, long long>, int> mpp;
private:
    int rec(long long num, long long den, int idx, vector<int>& nums, long long k) {
        if(idx >= n) {
            if(den == 1 && num == k) return 1;
            else return 0;
        }
        auto it = make_tuple(idx, num, den);
        if(mpp.count(it)) return mpp[it];
        long long nn = num * nums[idx], nd = den * nums[idx];
        int ans = 0, gc1 = gcd(nn, den), gc2 = gcd(nd, num);
        ans += rec(num, den, idx + 1, nums, k);
        ans += rec(nn / gc1, den / gc1, idx + 1, nums, k);
        ans += rec(num / gc2, nd / gc2, idx + 1, nums, k);
        return mpp[it] = ans;
    }
public:
    int countSequences(vector<int>& nums, long long k) {
        n = nums.size();
        return rec(1, 1, 0, nums, k);
    }
};