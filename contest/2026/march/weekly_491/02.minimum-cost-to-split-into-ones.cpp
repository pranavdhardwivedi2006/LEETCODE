class Solution {
public:
    int minCost(int n) {
        multiset<int> st; int ans = 0;
        for(int i = 0; i < n; i++) st.insert(1);
        while(st.size() > 1) {
            int a = *(st.begin());
            st.erase(st.begin());
            int b = *(st.begin());
            st.erase(st.begin());
            ans += a * b;
            st.insert(a + b);
        }
        return ans;
    }
};