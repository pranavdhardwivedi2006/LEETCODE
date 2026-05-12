class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] - a[0] > b[1] - b[0];
        });
        int l = 0, r = 1e9;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            bool possible = true;
            int energy = mid;
            for(auto& it : tasks) {
                if(energy < it[1]) {possible = false; break;}
                energy -= it[0];
            }
            if(possible) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};