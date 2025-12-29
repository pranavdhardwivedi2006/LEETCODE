class Solution {
unordered_map<string, string> trk;
unordered_map<string, bool> dp;
vector<string> arr;
private:
    bool build(int outer, int index) {
        if(outer == 0) return true;
        if(index == outer) {
            if(dp.find(arr[outer-1]) != dp.end()) return dp[arr[outer-1]];
            return dp[arr[outer-1]] = build(outer - 1, 0);
        }
        else {
            string temp = {arr[outer][index], arr[outer][index+1]};
            if(trk.find(temp) == trk.end()) return false;
            for(auto& it : trk[temp]) {
                arr[outer-1][index] = it; 
                if(build(outer, index + 1)) return true;
            }
        }
        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(auto& it : allowed) {
            string temp = {it[0], it[1]};
            trk[temp] += it[2];
        }
        int n = bottom.size(); arr.resize(n);
        for(int i = 0; i < n; i++) arr[i].resize(i+1, ' ');
        arr[n-1] = bottom; return build(n - 1, 0);
    }
};