class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size(), i = 0;
        vector<int> ans(n);
        for(auto& it : matrix) {
            int cnt = 0;
            for(auto& x : it) if(x) cnt++;
            ans[i++] = cnt;
        }
        return ans;
    }
};