class Solution {
public:
    long long removeZeros(long long n) {
        string temp = to_string(n);
        string ans;
        for(auto it : temp) if(it != '0') ans += it;
        return stoll(ans);
    }
};