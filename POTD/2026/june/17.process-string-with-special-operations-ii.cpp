class Solution {
char call(int index, long long len, long long k, string& s) {
    if(len == k) return s[index+1];
    if(s[index] == '*') return call(index - 1, len + 1, k, s);
    if(s[index] == '%') return call(index - 1, len, len - k - 1, s);
    if(s[index] == '#') {
        if(k >= len / 2) return call(index - 1, len / 2, k - len / 2, s);
        return call(index - 1, len / 2, k, s);
    }
    return call(index - 1, len - 1, k, s);
} 
public:
    char processStr(string s, long long k) {
        int n = s.size();
        long long curr = 0;
        for(int i = 0; i < n; i++) {
            auto it = s[i];
            if(it == '*') curr--;
            else if(it == '#') curr <<= 1;
            else if(it != '%') curr++;
            curr = max(curr, 0LL);
        }
        if(k >= curr) return '.';
        return call(n - 1, curr, k, s);
    }
};