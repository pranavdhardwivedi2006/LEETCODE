class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size(), curr = 0;
        vector<int> a(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == 'a') curr++;
            a[i] = curr;
        } int ans = n; curr = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'b') curr++;
            ans = min(ans, curr + a[i] - 1);
        }
        return ans;
    }
};