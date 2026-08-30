class Solution {
string find(int n) {
    string ans;
    while(n) {
        ans += '0' + (n & 1);
        n >>= 1;
    }
    int k = 8 - ans.size();
    reverse(ans.begin(), ans.end());
    ans = string(k, '0') + ans;
    return ans;
}
public:
    bool isPalindromic(string s) {
        string ans;
        for(auto it : s) ans += find(it);
        int l = 0, r = ans.size() - 1;
        while(l < r) {
            if(ans[l] != ans[r]) return false;
            l++, r--;
        }
        return true;
    }
};