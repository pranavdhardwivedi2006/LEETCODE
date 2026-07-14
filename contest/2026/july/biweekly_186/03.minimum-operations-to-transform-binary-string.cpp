class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        if(n == 1 && s1[0] != s2[0] && s1[0] == '1') return -1;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(s1[i] == s2[i]) continue;
            if(s1[i] == '0') ans++;
            else if(i + 1 < n && s1[i+1] != s2[i+1] && s1[i+1] == '1') {
                ans++; i++;
            } else ans += 2;
        }
        return ans;
    }
};