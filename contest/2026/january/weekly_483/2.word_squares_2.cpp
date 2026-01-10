class Solution {
vector<vector<string>> ans;
int n;
private:
    void find(int f, int s, int t, int idx, vector<string>& st) {
        if(f >= n || s >= n || t >= n) return ;
        if(idx == 0) {
            for(int i = 0; i < n; i++) find(i, s, t, idx + 1, st);
        }
        else if(idx == 1) {
            for(int i = 0; i < n; i++) if(i != f) find(f, i, t, idx + 1, st);
        }
        else if(idx == 2) {
            for(int i = 0; i < n; i++) if(i != f && i != s) find(f, s, i, idx + 1, st);
        }
        else {
            for(int i = 0; i < n; i++) {
                if(i != f && i != s && i != t) {
                    if(st[f][0] == st[t][0] && st[f][3] == st[i][0]) {
                        if(st[s][0] == st[t][3] && st[s][3] == st[i][3])
                            ans.push_back({st[f], st[t], st[i], st[s]});
                    }
                }
            }
        }
    }
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        n = words.size();
        find(0, 0, 0, 0, words);
        sort(ans.begin(), ans.end());
        return ans;
    }
};