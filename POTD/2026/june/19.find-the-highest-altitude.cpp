class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size(), max = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum = sum + gain[i];
            if (max < sum) {
                max = sum;
            }
        }
        return max;
    }
};