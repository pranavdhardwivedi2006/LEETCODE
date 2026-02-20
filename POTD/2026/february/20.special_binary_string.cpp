class Solution {
string ans, prev; int n;
string first, second, temp;
private:
    void comp(int i, string& s) {
        temp = prev + second + first + s.substr(i, n);
        ans = max(ans, temp);
    }
    void rec(int i, bool round, string& s) {
        if(i >= n || s[i] == '0') return ;
        int cnt0 = 0, cnt1 = 0;
        while(i < n) {
            s[i] == '0' ? cnt0++ : cnt1++;
            if(cnt0 > cnt1) return ;
            if(round) second += s[i++];
            else first += s[i++];
            if(cnt0 == cnt1) {
                if(round) comp(i, s);
                else {
                    rec(i, true, s);
                    second = "";
                }
            }
        }
    }
public:
    string makeLargestSpecial(string s) {
        n = s.size(); ans = s;
        for(int j = 0; j < 10; j++) {
            for(int i = 0; i < n; i++) {
                first = ""; rec(i, false, s); 
                prev += s[i];
            }
            s = ans; prev = "";
        }
        return s;
    }
};