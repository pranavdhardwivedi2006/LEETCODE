class Solution {
public:
    bool scoreBalance(string s) {
        int n = s.size();
        vector<int> trk(n, 0);
        for(int i = 0; i < n; i++) {
            if(i) trk[i] = trk[i-1] + s[i] - 'a' + 1;
            else trk[i] = s[i] - 'a' + 1;
        }
        int k = trk[n-1];
        for(auto& it : trk) if(it * 2 == k) return true;
        return false;
    }
};