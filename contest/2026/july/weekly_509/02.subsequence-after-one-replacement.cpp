class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> prefix(n), suffix(n);
        int l = 0, r = 0;
        while(l < n) {
            while(r < m && s[l] != t[r]) r++;
            prefix[l++] = r;
            if(r < m) r++;
        }
        l = n - 1, r = m - 1;
        while(l >= 0) {
            while(r >= 0 && s[l] != t[r]) r--;
            suffix[l--] = r;
            if(r >= 0) r--;
        }
        if(prefix.back() < m) return true;
        for(int i = 0; i < n; i++) {
            int prev = i ? prefix[i-1] : -1;
            int forward = i + 1 < n ? suffix[i+1] : m;
            if(forward - prev > 1) return true;
        }
        return false;
    }
};