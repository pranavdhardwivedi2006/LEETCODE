class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size(), m = boxGrid[0].size();
        vector<vector<char>> ans(m, vector<char>(n, '.'));
        for(int i = 0; i < n; i++) {
            int j = 0;
            while(j < m) {
                int cnt = 0, st = j;
                while(j < m && boxGrid[i][j] != '*') {
                    if(boxGrid[i][j] == '.') cnt++; j++;
                }
                while(st < j) {
                    if(cnt) st++, cnt--;
                    else ans[st++][n-i-1] = '#';
                }
                if(j < m) ans[j][n-i-1] = '*';
                j++;
            }
        }
        return ans;
    }
};