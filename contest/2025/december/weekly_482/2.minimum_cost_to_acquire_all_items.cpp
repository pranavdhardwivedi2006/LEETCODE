class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 1LL * costBoth * max(need1, need2);
        long long temp = 1LL * costBoth * min(need1, need2);
        temp += need1 > need2 ? 1LL * cost1 * (need1 - need2) : 1LL * cost2 * (need2 - need1);
        ans = min({ans, temp, 1LL * cost1 * need1 + 1LL * cost2 * need2});
        return ans;
    }
};