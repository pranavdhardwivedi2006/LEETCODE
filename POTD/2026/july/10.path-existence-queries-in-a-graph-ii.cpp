class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++) arr[i] = {nums[i], i};
        sort(arr.begin(), arr.end());

        vector<int> pos(n);
        for (int i = 0; i < n; i++) pos[arr[i].second] = i;

        int k = 2 + log2(n);
        vector<vector<int>> lift(n, vector<int>(k, -1));
        int l = 0, r = 0;
        while(l < n) {
            while(r < n && arr[r].first - arr[l].first <= maxDiff) r++;
            lift[l++][0] = r - 1;
        }
        for(int j = 1; j < k; j++) {
            for(int i = 0; i < n; i++) {
                if(lift[i][j-1] != -1) {
                    lift[i][j] = lift[lift[i][j-1]][j-1];
                }
            }
        }

        vector<int> ans; 
        ans.reserve(queries.size());
        for(auto it: queries) {
            int st = min(pos[it[0]], pos[it[1]]);
            int ta = max(pos[it[0]], pos[it[1]]);
            if(st == ta) { ans.push_back(0); continue; }
            int curr = st, steps = 0;
            for(int j = k - 1; j >= 0; j--) {
                if(lift[curr][j] < ta) {
                    curr = lift[curr][j];
                    steps += (1 << j);
                }
            }
            if(lift[curr][0] >= ta) ans.push_back(steps + 1);
            else ans.push_back(-1);
        }
        return ans;
    }
};