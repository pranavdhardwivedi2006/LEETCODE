class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0; int mini = INT_MAX;
        bool neg = false, zero = false;
        for(auto& it : matrix) {
            for(auto& x : it) {
                if(x == 0) zero = true;
                if(x < 0) neg = !neg;
                mini = min(mini, abs(x));
                sum += abs(x);
            }
        }
        if(neg && !zero) sum -= 2 * mini;
        return sum;
    }
};