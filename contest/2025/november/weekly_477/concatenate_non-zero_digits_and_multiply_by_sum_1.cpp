class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n), t; int k = 0;
        for(auto it : s) if(it != '0') t += it, k += (it - '0');
        return 1LL * k * (t.size() ? stoi(t) : 0);
    }
};