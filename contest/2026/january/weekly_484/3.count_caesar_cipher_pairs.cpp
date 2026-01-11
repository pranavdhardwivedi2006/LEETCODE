class Solution {
public:
    long long countPairs(vector<string>& words) {
        int n = words.size(), m = words[0].size();
        vector<vector<int>> trk(n, vector<int>(m - 1, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m - 1; j++) {
                trk[i][j] = (words[i][j] + 26 - words[i][j+1]) % 26;
            }
        }
        sort(trk.begin(), trk.end());
        int i = 0; long long ans = 0;
        while(i < n) {
            long long cnt = 1; int x = i++;
            while(i < n && trk[i] == trk[x]) cnt++, i++;
            ans += cnt * (cnt - 1) / 2;
        }
        return ans;
    }
};