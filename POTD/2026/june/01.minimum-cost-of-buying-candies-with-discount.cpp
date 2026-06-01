class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int i = cost.size() - 1, ans = 0;
        while(i >= 0) {
            ans += cost[i--];
            if(i >= 0) ans += cost[i--];
            i--;
        }
        return ans;
    }
};