class Solution {
int find(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
    int n = ls.size(), m = ws.size(), mini = ls[0] + ld[0], ans = INT_MAX; 
    for(int i = 0; i < n; i++) mini = min(mini, ls[i] + ld[i]); 
    for(int i = 0; i < m; i++) {
        int time = mini;
        if(ws[i] <= time) time += wd[i];
        else time = ws[i] + wd[i];
        ans = min(ans, time);
    }
    return ans;
}
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        return  min(find(ls, ld, ws, wd), find(ws, wd, ls, ld));        
    }
};