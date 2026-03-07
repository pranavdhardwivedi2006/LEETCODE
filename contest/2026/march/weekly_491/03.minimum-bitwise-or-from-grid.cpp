class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> take(n, vector<bool>(m, false));
        int ans = 0;
        for(int k = 17; k >= 0; k--) {
            bool one = false;
            for(int i = 0; i < n; i++) {
                bool is = false;
                for(int j = 0; j < m; j++) {
                    if(take[i][j]) continue ;
                    if((grid[i][j] >> k) & 1) continue ;
                    is = true; break;
                }
                if(!is) {one = true; break;}
            }
            if(!one) {
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < m; j++) {
                        if((grid[i][j] >> k) & 1) take[i][j] = true;
                    }
                }
            }
            else ans |= (1 << k);
        }
        return ans;
    }
};