class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size(), ans = 0;
        for(char c = 'a'; c <= 'z'; c++) {
            int l = 0, r = n - 1; 
            unordered_set<char> st; 
            while(l < n && s[l] != c) l++;
            while(r >= 0 && s[r] != c) r--;
            for(int i = l + 1; i < r; i++) st.insert(s[i]);
            ans += st.size(); 
        }
        return ans;
    }
};