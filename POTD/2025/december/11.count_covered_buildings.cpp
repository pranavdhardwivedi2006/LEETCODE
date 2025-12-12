class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int cnt = 0, m = buildings.size();
        map<int, vector<int>> mpp_1, mpp_2;
        for(int i = 0; i < m; i++) mpp_1[buildings[i][0]].push_back(buildings[i][1]);
        for(int i = 0; i < m; i++) mpp_2[buildings[i][1]].push_back(buildings[i][0]);
        for(auto& it : mpp_1) sort(it.second.begin(), it.second.end());
        for(auto& it : mpp_2) sort(it.second.begin(), it.second.end());
        for(auto it : mpp_1) {
            for(int j = 1; j < it.second.size() - 1; j++) {
                int k = mpp_2[it.second[j]].size(); 
                if(k > 2 && it.first != mpp_2[it.second[j]][0] && it.first != mpp_2[it.second[j]][k-1]) cnt++;
            }
        }
        return cnt;
    }
};