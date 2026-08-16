class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int dist = INT_MAX, ans = INT_MAX, i = 0;
        for(auto& it : drones) {
            int dis = abs(target[0] - it[0]) + abs(target[1] - it[1]);
            if(dis <= it[2] && dis < dist) {
                dist = dis;
                ans = i;
            }
            i++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};