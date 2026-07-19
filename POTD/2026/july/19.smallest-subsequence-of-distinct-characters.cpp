class Solution {
public:
    string smallestSubsequence(string s) {
        int last[26] = {0}, n = s.size();
        bool vis[26] = {0}; stack<char> st;
        for(int i = 0; i < n; i++) last[s[i]-'a'] = i;
        for(int i = 0; i < n; i++) {
            if(vis[s[i]-'a']) continue;
            while(!st.empty() && st.top() > s[i] && last[st.top()-'a'] > i) {
                vis[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]-'a'] = true;
        }
        string ans; 
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};