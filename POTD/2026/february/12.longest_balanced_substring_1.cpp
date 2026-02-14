class Solution {
private:
    bool check(map<char, int>& mpp) {
        int k = mpp.begin() -> second;
        for(auto& [u, v] : mpp) if(v != k) return false;
        return true;
    }
public:
    int longestBalanced(string s) {
        int ans = 0, n = s.size();
        for(int i = 0; i < n; i++) {
            map<char, int> mpp;
            for(int j = i; j < n; j++) {
                mpp[s[j]]++;
                if(check(mpp)) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};