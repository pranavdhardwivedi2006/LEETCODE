class Solution {
int MOD = 1e9 + 7;
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        unordered_set<int> st;
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        int H = hFences.size(), V = vFences.size();
        long long ans = -1;
        for(auto it : hFences) st.insert(it - 1); st.insert(m - 1);
        for(int i = 0; i < H; i++) {
            for(int j = i + 1; j < H; j++) {
                st.insert(hFences[j] - hFences[i]);
            }
            st.insert(m - hFences[i]);
        }
        for(auto it : vFences) {
            if(st.find(it - 1) != st.end()) {
                ans = max(ans, 1LL * (it - 1) * (it - 1));
            }
        }
        if(st.find(n - 1) != st.end()) {
            ans = max(ans, 1LL * (n - 1) * (n - 1));
        }
        for(int i = 0; i < V; i++) {
            for(int j = i + 1; j < V; j++) {
                if(st.find(vFences[j] - vFences[i]) != st.end()){
                    ans = max(ans, 1LL * (vFences[j] - vFences[i]) * (vFences[j] - vFences[i]));
                }
            }
            if(st.find(n - vFences[i]) != st.end()) {
                ans = max(ans, 1LL * (n - vFences[i]) * (n - vFences[i]));
            }
        }
        return ans % MOD;
    }
};