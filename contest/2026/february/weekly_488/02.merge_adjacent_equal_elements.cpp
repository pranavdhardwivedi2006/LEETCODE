class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long> st;
        for(int i = 0; i < nums.size(); i++) {
            long long x = nums[i];
            while(!st.empty() && st.top() == x) {
                x += st.top();
                st.pop();
            }
            st.push(x);
        }
        int n = st.size();
        vector<long long> ans(n);
        while(n--) {
            ans[n] = st.top();
            st.pop();
        }
        return ans;
    }
};