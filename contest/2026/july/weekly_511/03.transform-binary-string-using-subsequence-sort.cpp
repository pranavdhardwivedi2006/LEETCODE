class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int z = 0, o = 0;
        for(auto& it : s) {
            if(it == '0') z++;
            else o++;
        }
        vector<bool> ans;
        for(auto& it : strs) {
            if(it == s) {
                ans.push_back(true);
                continue;
            }
            int tz = 0, to = 0; 
            for(auto& x : it) {
                if(x == '0') tz++;
                if(x == '1') to++;
            }
            if(tz > z || to > o) {
                ans.push_back(false);
                continue;
            }
            string temp, ts; int x = 0, y = 0;
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == it[i]) continue;
                temp += it[i];
                ts += s[i];
                (s[i] == '0') ? x++ : y++;
            }
            bool possible = true;
            int j = 0;
            for(int i = 0; i < z - tz; i++) {
                while(temp[j] != '?') j++;
                temp[j] = '0';
            }
            for(int i = 0; i < o - to; i++) {
                while(temp[j] != '?') j++;
                temp[j] = '1';
            }
            int l = 0, r = 0, n = x + y;
            while(l < n && r < n) {
                while(l < n && !(temp[l] == '0' && ts[l] == '1')) l++;
                while(r < n && !(temp[r] == '1' && ts[r] == '0')) r++;
                if(l < n && r < n) {
                    if(l < r) swap(ts[l], ts[r]);
                    else {possible = false; break;}
                }
                else if(l < n && r >= n) possible = false;
                else if(l >= n && r < n) possible = false;
            }
            ans.push_back(possible);
        }
        return ans;
    }
};