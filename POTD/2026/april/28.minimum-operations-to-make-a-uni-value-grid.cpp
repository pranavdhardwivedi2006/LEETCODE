class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int t = grid[0][0] % x;
        vector<int> trk;
        for(int i = 0; i < grid.size(); i++){
            for(auto it : grid[i]) {
                if(it % x != t) return -1;
                trk.push_back(it);
            }  
        } 
        sort(trk.begin(), trk.end());
        int mid = trk.size() / 2, cnt = 0;
        for(int i = 0; i < trk.size(); i++){
            cnt += abs(trk[i] - trk[mid]) / x;
        }
        return cnt;
    }
};