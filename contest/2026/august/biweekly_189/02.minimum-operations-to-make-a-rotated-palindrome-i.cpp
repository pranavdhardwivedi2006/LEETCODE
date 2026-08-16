class Solution {
void rotate(string& s) {
    int c = s[0];
    for(int i = 1; i < s.size(); i++) {
        s[i-1] = s[i];
    }
    s.back() = c;
}
public:
    int minOperations(string s) {
        int ans = INT_MAX, rot = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            int op = 0;
            for(int j = 0; j < n / 2; j++) {
                int k = abs(s[j] - s[n-j-1]);
                op += min(k, 26 - k);
            }
            ans = min(ans, op + rot++);
            rotate(s);
        }
        return ans;
    }
};