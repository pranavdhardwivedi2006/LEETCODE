class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string s(n + m - 1, ' ');
        vector<bool> vis(n + m - 1, false);
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'F') continue ;
            for(int j = i; j < i + m; j++) {
                vis[j] = true;
                if(s[j] == ' ') s[j] = str2[j-i];
                if(s[j] != str2[j-i]) return "";
            }
        }
        for(auto& it : s) if(it == ' ') it = 'a';
        for(int i = 0; i < n; i++) {
            if(str1[i] == 'T') continue;
            bool is = true; int idx = -1;
            for(int j = i + m - 1; j >= i; j--) {
                if(s[j] != str2[j-i]) is = false;
                if(idx == -1 && !vis[j]) idx = j;
            }
            if(is) {
                if(idx == -1) return "";
                s[idx] = 'b';
            }
        }
        return s;
    }
};