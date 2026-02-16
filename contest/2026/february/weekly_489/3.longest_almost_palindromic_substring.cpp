class Solution {
private:
    int paths(string& s, int l, int r) {
        int n = s.size();
        while(l >= 0 && r < n) {
            if(s[l] != s[r]) return r - l - 1;
            l--; r++;
        }
        return r - l - 1;
    }
    int find(string& s, int l, int r, int n) {
        while(l >= 0 && r < n) {
            if(s[l] != s[r]) return max(paths(s, l - 1, r), paths(s, l, r + 1));
            l--, r++;
        }
        return r - l - 1 != n ? r - l : r - l - 1;
    }
public:
    int almostPalindromic(string s) {
        int ans = 1, n = s.size();
        for(int i = 0; i < n; i++) {
            int k = find(s, i, i, n);
            ans = max(ans, k);
            k = i ? find(s, i - 1, i, n) : 0;
            ans = max(ans, k);
            k = i + 1 < n ? find(s, i, i + 1, n) : 0;
            ans = max(ans, k);
        }
        return ans;
    }
};