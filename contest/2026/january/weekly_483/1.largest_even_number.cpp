class Solution {
public:
    string largestEven(string s) {
        int n = s.size(); int i = n - 1;
        while(i >= 0) {
            if((s[i] - '0') % 2 == 0) break ;
            i--;
        }
        string ans;
        for(int j = 0; j <= i; j++) ans += s[j];
        return ans;
    }
};