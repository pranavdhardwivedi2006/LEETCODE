class Solution {
bool check(int l, int r, string& s) {
    for(int i = l + 1; i <= r; i++) if(s[i-1] > s[i]) return false;
    return true;
}
public:
    int minOperations(string s) {
        bool is = true; int n = s.size(); 
        for(int i = 1; i < n; i++) if(s[i-1] > s[i]) is = false;
        if(is) return 0; 
        char mini = *min_element(s.begin(), s.end());
        char maxi = *max_element(s.begin(), s.end());
        if(mini == s[0] || maxi == s.back()) return 1;
        if(maxi == s[0] && mini == s.back()) {
            if(n <= 2) return -1;
            int cnt = 0, cnt1 = 0;
            for(int i = 0; i < n; i++) {
                if(s[i] == mini) cnt++;
                if(s[i] == maxi) cnt1++;
            }
            if(cnt == 1 && cnt1 == 1) return 3;
        }
        return 2;
    }
};