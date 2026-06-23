class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int c = 0, n = costs.size();
        sort(costs.begin(), costs.end());
        for (int i = 0; i < n; i++) {
            if (coins >= costs[i]) {
                c++;
                coins -= costs[i];
            } else break;
        }
        return c;
    }
};