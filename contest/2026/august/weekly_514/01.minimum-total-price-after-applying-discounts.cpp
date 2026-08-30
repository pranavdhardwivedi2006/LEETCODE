class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());
        int n = prices.size(), m = discounts.size();
        double ans = 0; int j = m - 1;
        for(int i = n - 1; i >= 0; i--) {
            if(j >= 0) {
                ans += 1.00 * prices[i] * (100 - discounts[j]) / 100.00;
                j--;
            } else {
                ans += prices[i];
            }
        }
        return ans;
    }
};