class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> nums(n, vector<int>(m, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[j][i] == '1') nums[j][i] = 1;
            }
        }
        for(int i = 0; i < m; i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(nums[j][i]) cnt++;
                else cnt = 0;
                nums[j][i] = cnt;
            }
        }
        int max = 0;
        for(int i = 0; i < n; i++) {
            stack<int> st;
            for(int j = 0; j < m; j++) {
                while(!st.empty() && nums[i][st.top()] > nums[i][j]) {
                    int k = st.top();
                    st.pop();
                    if(st.empty()) {
                        max = std::max(max, nums[i][k] * j);
                    }
                    else {
                        max = std::max(max, nums[i][k] * (j - st.top() - 1));
                    }
                }
                st.push(j);
            }
            while(!st.empty()) {
                int k = st.top();
                st.pop();
                if(st.empty()) {
                    max = std::max(max, nums[i][k] * m);
                }
                else {
                    max = std::max(max, nums[i][k] * (m - st.top() - 1));
                }
            }
        }
        return max;
    }
};