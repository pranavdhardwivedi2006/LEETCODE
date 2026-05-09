class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        set<vector<int>> st(points.begin(), points.end());
        if(st.count(target)) return 0;
        int ans = 1;
        while(points.size() < 500 && ans < 20) {
            int k = points.size();
            for(int i = 0; i < points.size(); i++) {
                for(int j = i + 1; j < points.size(); j++) {
                    int x = (points[i][0] + points[j][0]) / 2;
                    int y = (points[i][1] + points[j][1]) / 2;
                    int z = (points[i][2] + points[j][2]) / 2;
                    st.insert({x, y, z});
                }
            }
            if(st.count(target)) return ans;
            vector<vector<int>> temp(st.begin(), st.end());
            points = temp;
            ans++;
            if(k == points.size()) break;
        }
        return -1;
    }
};