class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        stack<int> st; int i = 0, n = positions.size();
        vector<tuple<int, int, char>> arr(n);
        for(int i = 0; i < n; i++) arr[i] = {positions[i], healths[i], directions[i]};
        sort(arr.begin(), arr.end());
        while(i < n) {
            auto& [pos1, hel1, dir1] = arr[i];
            if(dir1 == 'R') st.push(i);
            else {
                while(!st.empty()) {
                    auto& [pos2, hel2, dir2] = arr[st.top()];
                    if(dir2 == 'L') break;
                    if(hel2 > hel1) {hel2--; goto p;} st.pop();
                    if(hel2 == hel1) goto p; hel1--;
                }
                st.push(i);                
            }
            p : i++;
        }
        vector<int> ans(st.size()); int j = 0;
        unordered_map<int, int> mpp;
        while(!st.empty()) {
            auto& [pos, hel, dir] = arr[st.top()];
            st.pop(); mpp[pos] = hel;
        }
        for(auto& it : positions) if(mpp.count(it)) ans[j++] = mpp[it];
        return ans;
    }
};