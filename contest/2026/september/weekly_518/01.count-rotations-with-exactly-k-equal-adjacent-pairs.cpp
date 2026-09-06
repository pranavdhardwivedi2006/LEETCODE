class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            int curr = 0;
            for(int i = 1; i < n; i++) if(s[i-1] == s[i]) curr++;
            if(curr == k) ans++;
            char c = s[0];
            for(int i = 0; i < n - 1; i++) {
                s[i] = s[i+1];
            }
            s[n-1] = c;
        }
        return ans;
    }
};