class Solution {
public:
    vector<string> createGrid(int n, int m, int k) {
        vector<string> ans(n, string(m, '#'));
        for(int i = 0; i < n; i++) ans[i][0] = '.';
        for(int i = 0; i < m; i++) ans[n-1][i] = '.';
        if(k == 1) return ans;
        if(n == 1 || m == 1) return {};
        ans[n-2][1] = '.';
        if(k == 2) return ans;
        if(n == 2 && m == 2) return {};
        if(n - 3 >= 0) ans[n-3][1] = '.';
        else ans[n-2][2] = '.';
        if(k == 3) return ans;
        if(n == 2 && m == 3) return {};
        if(n == 3 && m == 2) return {};
        if(n == 2) {
            if(m < 4) return {};
            fill(ans[0].begin(), ans[0].end(), '#');
            ans[0][0] = ans[0][1] = ans[0][2] = ans[0][3] = '.';
            fill(ans[1].begin(), ans[1].end(), '.');
            return ans;
        }
        if(m == 2) {
            if(n < 4) return {};
            for(int i = 0; i < n; i++) {
                ans[i][1] = '.';
                if(i < 4) ans[i][0] = '.';
                else ans[i][0] = '#';
            }
            return ans;
        }
        for(auto& it : ans) fill(it.begin(), it.end(), '#');
        ans[0][0] = ans[0][1] = ans[1][0] = ans[1][2] = ans[1][1] = '.';
        ans[2][1] = ans[2][2] = '.';
        for(int i = 3; i < n; i++) ans[i][2] = '.';
        for(int i = 2; i < m; i++) ans[n-1][i] = '.';
        return ans;
    }
};