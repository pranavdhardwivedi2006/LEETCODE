class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size(), ans = -1, prev = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(capacity[i] >= itemSize && capacity[i] < prev) {
                prev = capacity[i];
                ans = i;
            }
        }
        return ans;
    }
};