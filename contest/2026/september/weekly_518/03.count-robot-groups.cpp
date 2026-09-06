class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        vector<int> p, s;
        for(int i = 0; i < n; i++) {
            if(!p.empty() && position[i] - p.back() <= distance) {
                p.pop_back();
                s.pop_back();
            }
            p.push_back(position[i]);
            s.push_back(speed[i]);
        }
        stack<int> st;
        for(int i = 0; i < p.size(); i++) {
            while(!st.empty() && (s[i] < s[st.top()] || p[i] - p[st.top()] <= distance)) st.pop();
            st.push(i);
        }
        return st.size();
    }
};