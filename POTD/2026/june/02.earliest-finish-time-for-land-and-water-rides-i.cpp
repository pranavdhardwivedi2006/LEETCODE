class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int ans = INT_MAX, n = ls.size(), m = ws.size();
        for(int i = 0; i < n; i++) {
            int time1 = ls[i] + ld[i];
            for(int j = 0; j < m; j++) {
                int time = time1;
                if(ws[j] <= time) time += wd[j];
                else time = ws[j] + wd[j];
                ans = min(ans, time);
            }
        }
        for(int i = 0; i < m; i++) {
            int time1 = ws[i] + wd[i];
            for(int j = 0; j < n; j++) {
                int time = time1;
                if(ls[j] <= time) time += ld[j];
                else time = ls[j] + ld[j];
                ans = min(ans, time);
            }
        }
        return ans;
    }
};