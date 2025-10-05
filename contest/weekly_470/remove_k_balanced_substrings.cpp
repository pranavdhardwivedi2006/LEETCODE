class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<pair<int, int>> trk; int i = 0, n = s.size();
        while(i < n) {
            int cnt = 0, cnt2 = 0, m = trk.size();
            while(i < n && s[i] == '(') cnt++, i++;
            while(i < n && s[i] == ')') cnt2++, i++;
            if(m && (trk.back().second == 0 || cnt == 0)) {
                trk.back().first += cnt; 
                trk.back().second += cnt2;  
            }
            else trk.push_back({cnt, cnt2});
            while(1) {
                auto [x, y] = trk.back(); 
                if(x < k || y < k) break;
                trk.pop_back();
                int p = min(x / k, y / k);
                p *= k; x -= p; y -= p;
                if(x == 0 && y == 0) break;
                if(trk.size()) {
                    if(trk.back().second == 0 || x == 0) {
                        trk.back().first += x;
                        trk.back().second += y;
                    }
                    else trk.push_back({x, y});
                }
                else trk.push_back({x, y}); 
            }
        }
        string ans;
        for(auto [u, v] : trk) {
            for(int i = 0; i < u; i++) ans += '(';
            for(int i = 0; i < v; i++) ans += ')';
        }
        return ans;
    }
};