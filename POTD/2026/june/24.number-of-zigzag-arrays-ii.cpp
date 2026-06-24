class Solution {
using ll = long long;
using mat = vector<vector<int>>;
#define MOD 1000000007
mat multiply(mat& a, mat& b) {
    int m = a.size();
    mat temp(m, vector<int>(m, 0));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < m; k++) {
                temp[i][j] = (temp[i][j] + 1LL * a[i][k] * b[k][j] % MOD) % MOD;
            }
        }
    }
    return temp;
}
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1, res = 0;
        mat t_mat(2 * m, vector<int>(2 * m));
        mat ans(2 * m, vector<int>(2 * m));
        for(int i = 0; i < m; i++) {
            ans[i][i] = ans[i+m][i+m] = 1;
            for(int j = 0; j < i; j++) {
                t_mat[i][j+m] = 1;
            }
            for(int j = i + 1; j < m; j++) {
                t_mat[i+m][j] = 1;
            }
        }
        n -= 1;
        while(n) {
            if(n & 1) ans = multiply(ans, t_mat);
            t_mat = multiply(t_mat, t_mat);
            n >>= 1;
        }
        for(auto& it : ans) {
            for(auto& x : it) res = (res + x) % MOD;
        }
        return res;
    }
};