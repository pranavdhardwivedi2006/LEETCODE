class Solution {
string ans, curr;
private:
    void rec(int idx, int n, int& k) {
        if(idx == n) {
            if(--k == 0) ans = curr;
            return ;
        }
        for(char c = 'a'; c < 'd'; c++) {
            if(curr.empty() || curr.back() != c) {
                curr += c; rec(idx + 1, n, k);
                curr.pop_back();
            }
        }
    }
public:
    string getHappyString(int n, int k) {
        rec(0, n, k); return ans;
    }
};